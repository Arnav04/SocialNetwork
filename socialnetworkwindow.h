#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "network.h"
#include "post.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SocialNetworkWindow;
}
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    // PRE: Constructor
    // POST: Initializes connections and hides/shows necessary buttons for login page
    SocialNetworkWindow(QWidget *parent = nullptr);

    // PRE: N/A
    // Post: Current user's profile view
    void loginButtonClicked();

    // PRE: Row and column of QTableWidgetItem selected
    // POST: Friend's profile view based on QTableWidgetItem selection
    void friendProfile(int row, int col);

    // PRE: Row and column of QTableWidgetItem selected from suggested friends table
    // POST: Adds suggested friend as friend
    void addFriend(int row, int col);

    // PRE: N/A
    // POST: Adds friend after clicking "Add Friend" button on another profile
    void addF();

    void likeClicked1();

    void laughClicked1();

    void dislikeClicked1();

    void likeClicked2();

    void laughClicked2();

    void dislikeClicked2();

    void likeClicked3();

    void laughClicked3();

    void dislikeClicked3();

    void likeClicked4();

    void laughClicked4();

    void dislikeClicked4();

    void likeClicked5();

    void laughClicked5();

    void dislikeClicked5();

    // PRE: N/A
    // POST: Destructor, socialnetworkwindow object and ui not needed after application is closed
    ~SocialNetworkWindow();

private:
    Ui::SocialNetworkWindow *ui;
    User* curr;
    User* other;
    Network* n;
};
#endif // SOCIALNETWORKWINDOW_H
