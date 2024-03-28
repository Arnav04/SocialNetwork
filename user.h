#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "post.h"

#ifndef USER_H
#define USER_H

class User {
public:
    // PRE: Accepts user's id, full name, year, zip code, and vector of friends as arguments
    // POST: Initializes arguments based on individual user object information
    User(int id, const std::string& name, int yr, int zip, const std::set<int>& friends);

    // PRE: N/A
    // POST: Initializes arguments to default 0 value
    User();

    // PRE: N/A
    // POST: Returns ID correspond to user
    int getId() const;

    // PRE: N/A
    // POST: Returns name correspond to user
    std::string getName() const;

    // PRE: N/A
    // POST: Returns year correspond to user
    int getYear() const;

    // PRE: N/A
    // POST: Returns zip code correspond to user
    int getZip() const;

    // PRE: N/A
    // POST: set of friends corresponding to user
    std::set<int>& getFriends();

    // PRE: Friend's ID
    // POST: Adds friend's ID to friend list
    void addFriend(int friendId);

    // PRE: Friend's ID
    // POST: Removes friend's ID to friend list
    void deleteFriend(int friendId);

    // PRE: Post pointer
    // POST: Adds post to message vector (vector of Post pointers)
    void addPost(Post* p);

    // PRE: N/A
    // Post: Returns messages_ vector of Post pointers for the user
    std::vector<Post*> getPosts();

    // PRE: int for "how many" most recent posts to include, boolean parameter to determine whether only public posts should be in the output string
    // POST: Returns concatenated toString() outputs of individual posts within the messages_ vector of the user
    std::string getPostsString(int howMany, bool showOnlyPublic);

    std::vector<Post*> getPublicMessages();


private:
    int id;
    std::string name;
    int yr;
    int zip;
    std::set<int> friends;
    std::vector<Post*> messages_;
};

#endif // USER_H
