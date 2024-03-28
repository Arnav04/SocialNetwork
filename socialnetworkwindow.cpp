#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"

bool primary = true;

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    n = new Network();
    n->readUsers("/Users/arnavdixit/Downloads/social_network_project/users.txt");
    n->readPosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
    curr = nullptr;
    other = nullptr;
    ui->setupUi(this);
    ui->friends_2->hide();
    ui->back->hide();
    ui->profile_label->hide();
    ui->friends->hide();
    ui->post1->hide();
    ui->add->hide();
    ui->like->hide();
    ui->laugh->hide();
    ui->dislike->hide();
    ui->like_2->hide();
    ui->laugh_2->hide();
    ui->dislike_2->hide();
    ui->like_3->hide();
    ui->laugh_3->hide();
    ui->dislike_3->hide();
    ui->like_4->hide();
    ui->laugh_4->hide();
    ui->dislike_4->hide();
    ui->like_5->hide();
    ui->laugh_5->hide();
    ui->dislike_5->hide();
    ui->p1->hide();
    ui->p2->hide();
    ui->p3->hide();
    ui->p4->hide();
    ui->p5->hide();
    ui->react_count->hide();
    ui->reaction_list->hide();

    ui->label->setText("Enter name");
    ui->signIn->setText("Login");

    connect(ui->signIn, &QPushButton::clicked, this, &SocialNetworkWindow::loginButtonClicked);
    connect(ui->friends, &QTableWidget::cellClicked, this, &SocialNetworkWindow::friendProfile);
    connect(ui->back, &QPushButton::clicked, this, &SocialNetworkWindow::loginButtonClicked);
    connect(ui->add, &QPushButton::clicked, this, &SocialNetworkWindow::addF);
    connect(ui->friends_2, &QTableWidget::cellClicked, this, &SocialNetworkWindow::addFriend);
    connect(ui->like, &QPushButton::clicked, this, &SocialNetworkWindow::likeClicked1);
    connect(ui->laugh, &QPushButton::clicked, this, &SocialNetworkWindow::laughClicked1);
    connect(ui->dislike, &QPushButton::clicked, this, &SocialNetworkWindow::dislikeClicked1);
    connect(ui->like_2, &QPushButton::clicked, this, &SocialNetworkWindow::likeClicked2);
    connect(ui->laugh_2, &QPushButton::clicked, this, &SocialNetworkWindow::laughClicked2);
    connect(ui->dislike_2, &QPushButton::clicked, this, &SocialNetworkWindow::dislikeClicked2);
    connect(ui->like_3, &QPushButton::clicked, this, &SocialNetworkWindow::likeClicked3);
    connect(ui->laugh_3, &QPushButton::clicked, this, &SocialNetworkWindow::laughClicked3);
    connect(ui->dislike_3, &QPushButton::clicked, this, &SocialNetworkWindow::dislikeClicked3);
    connect(ui->like_4, &QPushButton::clicked, this, &SocialNetworkWindow::likeClicked4);
    connect(ui->laugh_4, &QPushButton::clicked, this, &SocialNetworkWindow::laughClicked4);
    connect(ui->dislike_4, &QPushButton::clicked, this, &SocialNetworkWindow::dislikeClicked4);
    connect(ui->like_5, &QPushButton::clicked, this, &SocialNetworkWindow::likeClicked5);
    connect(ui->laugh_5, &QPushButton::clicked, this, &SocialNetworkWindow::laughClicked5);
    connect(ui->dislike_5, &QPushButton::clicked, this, &SocialNetworkWindow::dislikeClicked5);
}

void SocialNetworkWindow::loginButtonClicked()
{
    primary = true;
    if (n->getId(ui->text->toPlainText().toStdString()) == -1)
    {
        ui->label->setText("Enter a valid name");
        return;
    }

    ui->react_count->clear();
    ui->react_count->setRowCount(0);
    ui->react_count->setColumnCount(0);
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
    ui->react_count->show();
    ui->reaction_list->hide();

    curr = n->getUser(n->getId(name));

    ui->profile_label->setText("My Profile");
    ui->post1->setText(QString::fromStdString(n->getPostsString(curr->getId(), 5, false)));

    int p = curr->getPosts().size();
    if (p == 0)
    {
        ui->p1->hide();
        ui->like->hide();
        ui->laugh->hide();
        ui->dislike->hide();
        ui->p2->hide();
        ui->like_2->hide();
        ui->laugh_2->hide();
        ui->dislike_2->hide();
        ui->p3->hide();
        ui->like_3->hide();
        ui->laugh_3->hide();
        ui->dislike_3->hide();
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 1)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->hide();
        ui->like_2->hide();
        ui->laugh_2->hide();
        ui->dislike_2->hide();
        ui->p3->hide();
        ui->like_3->hide();
        ui->laugh_3->hide();
        ui->dislike_3->hide();
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 2)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->hide();
        ui->like_3->hide();
        ui->laugh_3->hide();
        ui->dislike_3->hide();
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 3)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->show();
        ui->p3->setText("Post 3");
        ui->like_3->show();
        ui->like_3->setText("👍");
        ui->laugh_3->show();
        ui->laugh_3->setText("😂");
        ui->dislike_3->show();
        ui->dislike_3->setText("👎");
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 4)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->show();
        ui->p3->setText("Post 3");
        ui->like_3->show();
        ui->like_3->setText("👍");
        ui->laugh_3->show();
        ui->laugh_3->setText("😂");
        ui->dislike_3->show();
        ui->dislike_3->setText("👎");
        ui->p4->show();
        ui->p4->setText("Post 4");
        ui->like_4->show();
        ui->like_4->setText("👍");
        ui->laugh_4->show();
        ui->laugh_4->setText("😂");
        ui->dislike_4->show();
        ui->dislike_4->setText("👎");
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p >= 5)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->show();
        ui->p3->setText("Post 3");
        ui->like_3->show();
        ui->like_3->setText("👍");
        ui->laugh_3->show();
        ui->laugh_3->setText("😂");
        ui->dislike_3->show();
        ui->dislike_3->setText("👎");
        ui->p4->show();
        ui->p4->setText("Post 4");
        ui->like_4->show();
        ui->like_4->setText("👍");
        ui->laugh_4->show();
        ui->laugh_4->setText("😂");
        ui->dislike_4->show();
        ui->dislike_4->setText("👎");
        ui->p5->show();
        ui->p5->setText("Post 5");
        ui->like_5->show();
        ui->like_5->setText("👍");
        ui->laugh_5->show();
        ui->laugh_5->setText("😂");
        ui->dislike_5->show();
        ui->dislike_5->setText("👎");
    }


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
    ui->react_count->clear();
    ui->react_count->setRowCount(0);
    ui->react_count->setColumnCount(0);
    ui->reaction_list->hide();
    primary = false;
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
    int p = other->getPublicMessages().size();
    if (p == 0)
    {
        ui->p1->hide();
        ui->like->hide();
        ui->laugh->hide();
        ui->dislike->hide();
        ui->p2->hide();
        ui->like_2->hide();
        ui->laugh_2->hide();
        ui->dislike_2->hide();
        ui->p3->hide();
        ui->like_3->hide();
        ui->laugh_3->hide();
        ui->dislike_3->hide();
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 1)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->hide();
        ui->like_2->hide();
        ui->laugh_2->hide();
        ui->dislike_2->hide();
        ui->p3->hide();
        ui->like_3->hide();
        ui->laugh_3->hide();
        ui->dislike_3->hide();
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 2)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->hide();
        ui->like_3->hide();
        ui->laugh_3->hide();
        ui->dislike_3->hide();
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 3)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->show();
        ui->p3->setText("Post 3");
        ui->like_3->show();
        ui->like_3->setText("👍");
        ui->laugh_3->show();
        ui->laugh_3->setText("😂");
        ui->dislike_3->show();
        ui->dislike_3->setText("👎");
        ui->p4->hide();
        ui->like_4->hide();
        ui->laugh_4->hide();
        ui->dislike_4->hide();
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p == 4)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->show();
        ui->p3->setText("Post 3");
        ui->like_3->show();
        ui->like_3->setText("👍");
        ui->laugh_3->show();
        ui->laugh_3->setText("😂");
        ui->dislike_3->show();
        ui->dislike_3->setText("👎");
        ui->p4->show();
        ui->p4->setText("Post 4");
        ui->like_4->show();
        ui->like_4->setText("👍");
        ui->laugh_4->show();
        ui->laugh_4->setText("😂");
        ui->dislike_4->show();
        ui->dislike_4->setText("👎");
        ui->p5->hide();
        ui->like_5->hide();
        ui->laugh_5->hide();
        ui->dislike_5->hide();
    }
    else if (p >= 5)
    {
        ui->p1->show();
        ui->p1->setText("Post 1");
        ui->like->show();
        ui->like->setText("👍");
        ui->laugh->show();
        ui->laugh->setText("😂");
        ui->dislike->show();
        ui->dislike->setText("👎");
        ui->p2->show();
        ui->p2->setText("Post 2");
        ui->like_2->show();
        ui->like_2->setText("👍");
        ui->laugh_2->show();
        ui->laugh_2->setText("😂");
        ui->dislike_2->show();
        ui->dislike_2->setText("👎");
        ui->p3->show();
        ui->p3->setText("Post 3");
        ui->like_3->show();
        ui->like_3->setText("👍");
        ui->laugh_3->show();
        ui->laugh_3->setText("😂");
        ui->dislike_3->show();
        ui->dislike_3->setText("👎");
        ui->p4->show();
        ui->p4->setText("Post 4");
        ui->like_4->show();
        ui->like_4->setText("👍");
        ui->laugh_4->show();
        ui->laugh_4->setText("😂");
        ui->dislike_4->show();
        ui->dislike_4->setText("👎");
        ui->p5->show();
        ui->p5->setText("Post 5");
        ui->like_5->show();
        ui->like_5->setText("👍");
        ui->laugh_5->show();
        ui->laugh_5->setText("😂");
        ui->dislike_5->show();
        ui->dislike_5->setText("👎");
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

void SocialNetworkWindow::likeClicked1()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[0]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[0]->addLikes();
            curr->getPosts()[0]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[0]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[0]->getLikes()));

            int i = 0;
            for (int u : curr->getPosts()[0]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[0]->subtractLikes();
            curr->getPosts()[0]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[0]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[0]->getLikes()));
            int i = 0;
            for (int u : curr->getPosts()[0]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[0]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[0]->addLikes();
            other->getPosts()[0]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[0]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[0]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[0]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[0]->subtractLikes();
            other->getPosts()[0]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[0]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[0]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[0]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::laughClicked1()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[0]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[0]->addLaughs();
            curr->getPosts()[0]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[0]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[0]->getLaugh()));

            int i = 0;
            for (int u : curr->getPosts()[0]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[0]->subtractLaughs();
            curr->getPosts()[0]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[0]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[0]->getLaugh()));
            int i = 0;
            for (int u : curr->getPosts()[0]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[0]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[0]->addLaughs();
            other->getPosts()[0]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[0]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[0]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[0]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[0]->subtractLaughs();
            other->getPosts()[0]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[0]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[0]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[0]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::dislikeClicked1()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[0]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[0]->addDislikes();
            curr->getPosts()[0]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[0]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[0]->getDislike()));

            int i = 0;
            for (int u : curr->getPosts()[0]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[0]->subtractDislikes();
            curr->getPosts()[0]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[0]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[0]->getDislike()));
            int i = 0;
            for (int u : curr->getPosts()[0]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[0]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[0]->addDislikes();
            other->getPosts()[0]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[0]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[0]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[0]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[0]->subtractDislikes();
            other->getPosts()[0]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[0]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[0]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[0]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::likeClicked2()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[1]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[1]->addLikes();
            curr->getPosts()[1]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[1]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[1]->getLikes()));

            int i = 0;
            for (int u : curr->getPosts()[1]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[1]->subtractLikes();
            curr->getPosts()[1]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[1]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[1]->getLikes()));
            int i = 0;
            for (int u : curr->getPosts()[1]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[1]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[1]->addLikes();
            other->getPosts()[1]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[1]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[1]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[1]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[1]->subtractLikes();
            other->getPosts()[1]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[1]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[1]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[1]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::laughClicked2()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[1]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[1]->addLaughs();
            curr->getPosts()[1]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[1]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[1]->getLaugh()));

            int i = 0;
            for (int u : curr->getPosts()[1]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[1]->subtractLaughs();
            curr->getPosts()[1]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[1]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[1]->getLaugh()));
            int i = 0;
            for (int u : curr->getPosts()[1]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[1]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[1]->addLaughs();
            other->getPosts()[1]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[1]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[1]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[1]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[1]->subtractLaughs();
            other->getPosts()[1]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[1]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[1]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[1]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
}

void SocialNetworkWindow::dislikeClicked2()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[1]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[1]->addDislikes();
            curr->getPosts()[1]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[1]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[1]->getDislike()));

            int i = 0;
            for (int u : curr->getPosts()[1]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[1]->subtractDislikes();
            curr->getPosts()[1]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[1]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[1]->getDislike()));
            int i = 0;
            for (int u : curr->getPosts()[1]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[1]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[1]->addDislikes();
            other->getPosts()[1]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[1]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[1]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[1]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[1]->subtractDislikes();
            other->getPosts()[1]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[1]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[1]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[1]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::likeClicked3()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[2]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[2]->addLikes();
            curr->getPosts()[2]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[2]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[2]->getLikes()));

            int i = 0;
            for (int u : curr->getPosts()[2]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[2]->subtractLikes();
            curr->getPosts()[2]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[2]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[2]->getLikes()));
            int i = 0;
            for (int u : curr->getPosts()[2]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[2]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[2]->addLikes();
            other->getPosts()[2]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[2]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[2]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[2]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[2]->subtractLikes();
            other->getPosts()[2]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[2]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[2]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[2]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::laughClicked3()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[2]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[2]->addLaughs();
            curr->getPosts()[2]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[2]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[2]->getLaugh()));

            int i = 0;
            for (int u : curr->getPosts()[2]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[2]->subtractLaughs();
            curr->getPosts()[2]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[2]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[2]->getLaugh()));
            int i = 0;
            for (int u : curr->getPosts()[2]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[2]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[2]->addLaughs();
            other->getPosts()[2]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[2]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[2]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[2]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[2]->subtractLaughs();
            other->getPosts()[2]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[2]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[2]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[2]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::dislikeClicked3()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[2]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[2]->addDislikes();
            curr->getPosts()[2]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[2]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[2]->getDislike()));

            int i = 0;
            for (int u : curr->getPosts()[2]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[2]->subtractDislikes();
            curr->getPosts()[2]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[2]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[2]->getDislike()));
            int i = 0;
            for (int u : curr->getPosts()[2]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[2]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[2]->addDislikes();
            other->getPosts()[2]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[2]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[2]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[2]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[2]->subtractDislikes();
            other->getPosts()[2]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[2]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[2]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[2]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::likeClicked4()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[3]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[3]->addLikes();
            curr->getPosts()[3]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[3]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[3]->getLikes()));
            int i = 0;
            for (int u : curr->getPosts()[3]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[3]->subtractLikes();
            curr->getPosts()[3]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[3]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[3]->getLikes()));
            int i = 0;
            for (int u : curr->getPosts()[3]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
    else
    {
        for (int i : other->getPosts()[3]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[3]->addLikes();
            other->getPosts()[3]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[3]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[3]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[3]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[3]->subtractLikes();
            other->getPosts()[3]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[3]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[3]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[3]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::laughClicked4()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[3]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[3]->addLaughs();
            curr->getPosts()[3]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[3]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[3]->getLaugh()));

            int i = 0;
            for (int u : curr->getPosts()[3]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[3]->subtractLaughs();
            curr->getPosts()[3]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[3]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[3]->getLaugh()));
            int i = 0;
            for (int u : curr->getPosts()[3]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[3]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[3]->addLaughs();
            other->getPosts()[3]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[3]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[3]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[3]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[3]->subtractLaughs();
            other->getPosts()[3]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[3]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[3]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[3]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::dislikeClicked4()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[3]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[3]->addDislikes();
            curr->getPosts()[3]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[3]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[3]->getDislike()));
            int i = 0;
            for (int u : curr->getPosts()[3]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[3]->subtractDislikes();
            curr->getPosts()[3]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[3]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[3]->getDislike()));
            int i = 0;
            for (int u : curr->getPosts()[3]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[3]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[3]->addDislikes();
            other->getPosts()[3]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[3]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[3]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[3]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[3]->subtractDislikes();
            other->getPosts()[3]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[3]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[3]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[3]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::likeClicked5()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[4]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[4]->addLikes();
            curr->getPosts()[4]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[4]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[4]->getLikes()));

            int i = 0;
            for (int u : curr->getPosts()[4]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[4]->subtractLikes();
            curr->getPosts()[4]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[4]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(curr->getPosts()[4]->getLikes()));
            int i = 0;
            for (int u : curr->getPosts()[4]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[4]->getLikedUsers())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[4]->addLikes();
            other->getPosts()[4]->setLikedUsers(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[4]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[4]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[4]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[4]->subtractLikes();
            other->getPosts()[4]->remove_likes();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[4]->getLikedUsers().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Likes: " + QString::number(other->getPosts()[4]->getLikes()));
            int i = 0;
            for (int u : other->getPosts()[4]->getLikedUsers())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::laughClicked5()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[4]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[4]->addLaughs();
            curr->getPosts()[4]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[4]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[4]->getLaugh()));

            int i = 0;
            for (int u : curr->getPosts()[4]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[4]->subtractLaughs();
            curr->getPosts()[4]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[4]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(curr->getPosts()[4]->getLaugh()));
            int i = 0;
            for (int u : curr->getPosts()[4]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[4]->getLaughs())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[4]->addLaughs();
            other->getPosts()[4]->setLaughs(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[4]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[4]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[4]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[4]->subtractLaughs();
            other->getPosts()[4]->remove_laugh();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[4]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Laughs: " + QString::number(other->getPosts()[4]->getLaugh()));
            int i = 0;
            for (int u : other->getPosts()[4]->getLaughs())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

void SocialNetworkWindow::dislikeClicked5()
{
    bool x = true;
    if (primary == true)
    {
        for (int i : curr->getPosts()[4]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            curr->getPosts()[4]->addDislikes();
            curr->getPosts()[4]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[4]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[4]->getDislike()));

            int i = 0;
            for (int u : curr->getPosts()[4]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            curr->getPosts()[4]->subtractDislikes();
            curr->getPosts()[4]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(curr->getPosts()[4]->getLaughs().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(curr->getPosts()[4]->getDislike()));
            int i = 0;
            for (int u : curr->getPosts()[4]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
    }
    else
    {
        for (int i : other->getPosts()[4]->getDislikes())
        {
            if (i == curr->getId())
            {
                x = false;
            }
        }

        if (x == true)
        {
            int id = curr->getId();
            other->getPosts()[4]->addDislikes();
            other->getPosts()[4]->setDislikes(id);
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[4]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[4]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[4]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }
        else
        {
            other->getPosts()[4]->subtractDislikes();
            other->getPosts()[4]->remove_dislike();
            n->writePosts("/Users/arnavdixit/Downloads/social_network_project/posts1.txt");
            ui->react_count->setRowCount(other->getPosts()[4]->getDislikes().size());
            ui->react_count->setColumnCount(1);
            ui->reaction_list->show();
            ui->reaction_list->setText("Dislikes: " + QString::number(other->getPosts()[4]->getDislike()));
            int i = 0;
            for (int u : other->getPosts()[4]->getDislikes())
            {
                QTableWidgetItem *f = new QTableWidgetItem(QString::fromStdString(n->getUser(u)->getName()));
                ui->react_count->setItem(i, 0, f);
                i++;
            }
        }

    }
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}
