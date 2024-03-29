#include <vector>
#include <string>

#ifndef POST_H
#define POST_H

class Post {
public:
	
    // PRE: ID, Post message, likes
    // POST: initializes private variables
    Post(int messageId, int ownerId, std::string message, int likes, int laughs, int dislikes, std::vector<int> l_names, std::vector<int> la_names, std::vector<int> d_names);

    // PRE: N/A
    // POST: Initializes all private fields to default values
    Post();

    // PRE: N/A
    // POST: Returns string containing post message and number of likes
    virtual std::string toString();

    // PRE: N/A
    // POST: Gets message's ID
    int getMessageId() const;

    // PRE: N/A
    // POST: Gets user's ID where post is directed to
    int getOwnerId() const;

    // PRE: N/A
    // POST: Gets post's message
    std::string getMessage() const;

    // PRE: N/A
    // POST: Gets post's likes
    int getLikes() const;

    // PRE: N/A
    // POST: Returns "" since Post has no author
    virtual std::string getAuthor() const;

    // PRE: N/A
    // POST: Returns true since all regular posts are public
    virtual bool getIsPublic() const;

    void addLikes();

    void addLaughs();

    void addDislikes();

    std::vector<int> getLikedUsers();

    std::vector<int> getLaughs();

    std::vector<int> getDislikes();

    void setLikedUsers(int id);

    void setLaughs(int id);

    void setDislikes(int id);

    void subtractLikes();

    void subtractLaughs();

    void subtractDislikes();

    void remove_likes();

    void remove_laugh();

    void remove_dislike();

    int getLaugh();

    int getDislike();

private:
    int messageId_;
    int ownerId_;
    std::string message_;
    int likes_;
    int laugh_count;
    int dislike_count;
    std::vector<int> liked_users;
    std::vector<int> laughs;
    std::vector<int> dislikes;
};

class IncomingPost : public Post {
public:
    // PRE: MessageId, User's ID, Post's message, number of likes, boolean to represent whether post is public, author of post
    // POST: Initializes private variables
    IncomingPost(int messageId, int ownerId, std::string message, int likes, int laughs, int dislikes, std::vector<int> like_list, std::vector<int> laugh_list, std::vector<int> dislike_list, bool isPublic, std::string author);
    
    // PRE: N/A
    // POST: Initializes all private variables to default values
    IncomingPost();
    
    // PRE: N/A
    // POST: Returns string containing post's toString, preceded by author of the IncomingPost
    std::string toString();

    // PRE: N/A
    // POST: Returns author of IncomingPost
    std::string getAuthor() const;

    // PRE: N/A
    // POST: Returns boolean value of whether post is public
    bool getIsPublic() const;

private:
    std::string author_;
    bool isPublic_;
};

#endif
