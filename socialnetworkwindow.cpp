#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    n = new Network();
    n->readUsers("/Users/arnavdixit/Downloads/social_network_project/users.txt");
    n->readPosts("/Users/arnavdixit/Downloads/social_network_project/posts.txt");
    curr = nullptr;
    other = nullptr;
    ui->setupUi(this);
    ui->friends_2->hide();
    ui->back->hide();
    ui->profile_label->hide();
    ui->friends->hide();
    ui->post1->hide();
    ui->add->hide();
    ui->label->setText("Enter name");
    ui->signIn->setText("Login");

    connect(ui->signIn, &QPushButton::clicked, this, &SocialNetworkWindow::loginButtonClicked);
    connect(ui->friends, &QTableWidget::cellClicked, this, &SocialNetworkWindow::friendProfile);
    connect(ui->back, &QPushButton::clicked, this, &SocialNetworkWindow::loginButtonClicked);
    connect(ui->add, &QPushButton::clicked, this, &SocialNetworkWindow::addF);
    connect(ui->friends_2, &QTableWidget::cellClicked, this, &SocialNetworkWindow::addFriend);
}

void SocialNetworkWindow::loginButtonClicked()
{
    if (n->getId(ui->text->toPlainText().toStdString()) == -1)
    {
        ui->label->setText("Enter a valid name");
        return;
    }

    ui->label->hide();
    ui->signIn->hide();
    other = nullptr;
    std::string name = ui->text->toPlainText().toStdString();
    ui->text->hide();
    ui->back->hide();
    ui->add->hide();
    ui->friends_2->show();
    ui->profile_label->show();
    ui->friends->show();
    ui->post1->show();

    curr = n->getUser(n->getId(name));

    ui->profile_label->setText("My Profile");
    ui->post1->setText(QString::fromStdString(n->getPostsString(curr->getId(), 5, false)));

    ui->friends->setRowCount(curr->getFriends().size());
    ui->friends->setColumnCount(1);

    int i = 0;
    for (int fr : curr->getFriends())
    {
        QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(fr)->getName()));
        ui->friends->setItem(i, 0, f);
        i++;
    }

    int score;

    std::vector<int> suggest = n->suggestFriends(n->getId(name), score);
    ui->friends_2->setRowCount(suggest.size());
    ui->friends_2->setColumnCount(1);

    int j = 0;
    for (int fr : suggest)
    {
        QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(fr)->getName()));
        ui->friends_2->setItem(j, 0, f);
        j++;
    }
}

void SocialNetworkWindow::friendProfile(int row, int col)
{
    QTableWidgetItem* f = ui->friends->item(row, col);
    QString fName = f->text();
    std::string frndName = fName.toStdString();
    int friendId = n->getId(frndName);
    other = n->getUser(friendId);
    ui->back->show();
    ui->friends_2->hide();
    ui->add->show();
    ui->back->setText("My profile");
    ui->add->setText("Add friend");
    std::string title = other->getName() + "'s Profile";
    ui->profile_label->setText(QString::fromStdString(title));
    ui->post1->setText(QString::fromStdString(n->getPostsString(other->getId(), 5, true)));
    ui->friends->setRowCount(other->getFriends().size());
    ui->friends->setColumnCount(1);
    int i = 0;
    for (int fr : other->getFriends())
    {
        QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(fr)->getName()));
        ui->friends->setItem(i, 0, f);
        i++;
    }
}

void SocialNetworkWindow::addF()
{
    int friendId = other->getId();
    curr->addFriend(friendId);
    other->addFriend(curr->getId());
    n->writeUsers("/Users/arnavdixit/Downloads/social_network_project/users.txt");
    ui->friends->clearContents();
    ui->friends->setRowCount(other->getFriends().size());
    int i = 0;
    for (int fr : other->getFriends())
    {
        QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(fr)->getName()));
        ui->friends->setItem(i, 0, f);
        i++;
    }
}

void SocialNetworkWindow::addFriend(int row, int column)
{
    QTableWidgetItem* f = ui->friends_2->item(row, column);
    QString fName = f->text();
    std::string friendName = fName.toStdString();
    int friendId = n->getId(friendName);
    curr->addFriend(friendId);
    User* x = n->getUser(friendId);
    x->addFriend(curr->getId());
    n->writeUsers("/Users/arnavdixit/Downloads/social_network_project/users.txt");
    ui->friends->clearContents();
    ui->friends->setRowCount(curr->getFriends().size());
    int i = 0;
    for (int fr : curr->getFriends())
    {
        QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(fr)->getName()));
        ui->friends->setItem(i, 0, f);
        i++;
    }
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}
