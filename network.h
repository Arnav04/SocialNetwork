#include <iostream>
#include "user.h"
#include "post.h"
#include <string>
#include <vector>
#include <queue>
#include <stack>
#ifndef NETWORK_H
#define NETWORK_H

class Network {
public:
    /*
    PRE: No arguments 
    POST: Initializes users vector to default empty value
    */
    Network();

    // PRE: Name of file
    // POST: Reads users from file and intializes info
    int readUsers(const char* fileName);

    // PRE: Name of file
    // POST: Writes users' info from file
    int writeUsers(const char* fileName);

    // PRE: Pointer to user object
    // POST: Adds user object to users vector
    void addUser(User* u);

    // PRE: Accepts full names of 2 users
    // POST: Connects users to each other as friends
    int addConnection(const std::string s1, const std::string s2);

    // PRE: Accepts full names of 2 users
    // POST: Removes users' connection to each other as friends
    int deleteConnection(const std::string s1, const std::string s2);

    // PRE: Accepts username
    // POST: Returns id of the user
    int getId(const std::string& name);

    // PRE: Accepts user's id
    // POST: Returns name corresponding to id of user
    User* getUser(int id);

    // PRE: N/A
    // POST: Returns number of users in users queue
    int numUsers() const;

    // PRE: N/A
    // POST: Prints all users 
    void printUsers();
    
    // PRE: Accepts a user's full name
    // POST: Prints the user's friends
    void printFriends(std::string& name);

    // PRE: Accepts a source user and a destination user's ID
    // POST: Returns a vector (of the user's IDs) of the shortest path between the two users
    std::vector<int> shortestPath(int from, int to);

    // PRE: Accepts a source user and reference of destination user (not initialized before function is ran), and the desired distance from the source user
    // POST: Returns a vector of the user's IDs containing the path from the source user to destination user the specified distance away  
    std::vector<int> distanceUser(int from, int& to, int distance);

    // PRE: Accepts a source user and reference to highest score
    // POST: Returns the users with the highest amount of common friends with the source friend (limited to friends of friends of the original user)
    std::vector<int> suggestFriends(int who, int& score);

    // PRE: N/A
    // POST: Returns the groups of connected friends from the network in one vector of vectors (the individual vectors inside the vector represents the groups of connected friends)
    std::vector<std::vector<int>> groups();

    // PRE: User ID, actual message, number of likes from the post, boolean parameter to determine whether post is IncomingPost, author of incomingPost, boolean val to determine if post is public
    // POST: Adds post to user's messages_ vector
    void addPost(int ownerId, std::string message, int likes, int laughs, int dislikes, std::vector<int> lc, std::vector<int> lac, std::vector<int> dc,  bool isIncoming, std::string authorName, bool isPublic);

    // PRE: User's ID, int for "how many" most recent posts to include, boolean parameter to determine whether only public posts should be in the output string
    // POST: Returns concatenated toString() outputs of individual posts within the messages_ vector of the specified user
    std::string getPostsString(int ownerId, int howMany, bool showOnlyPublic);

    // PRE: File name
    // POST: Reads each line from provided file to add post to approrpriate user
    int readPosts(const char* fname);

    // PRE: File name
    // POST: Takes all posts from all users and writes each post attribute to each individual line
    int writePosts(const char* fname);

    static bool comparisonFunc(Post* p1, Post* p2);

private:
    std::vector<User*> users;
};

#endif 
