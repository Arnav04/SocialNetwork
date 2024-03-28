#include "post.h"

Post::Post(int messageId, int ownerId, std::string message, int likes, int laughs, int dislikes, std::vector<int> l_names, std::vector<int> la_names, std::vector<int> d_names) : messageId_(messageId), ownerId_(ownerId), message_(message), likes_(likes), laugh_count(laughs), dislike_count(dislikes), liked_users(l_names), laughs(la_names), dislikes(d_names) {}

Post::Post()
{
    messageId_ = 0; 
    ownerId_ = 0;
    message_ = "";
    likes_ = 0;
    laugh_count = 0;
    dislike_count = 0;

}

std::string Post::toString()
{
    return message_ + " Liked by " + std::to_string(likes_) + " people.";
}

int Post::getMessageId() const 
{
    return messageId_;
}

int Post::getOwnerId() const
{
    return ownerId_;
}

std::string Post::getMessage() const 
{
    return message_;
}

int Post::getLikes() const 
{
    return likes_;
}

std::string Post::getAuthor() const
{
    return "";
} 

bool Post::getIsPublic() const
{
    return true;
}

void Post::addLikes()
{
    likes_++;
}

void Post::addLaughs()
{
    laugh_count++;
}

void Post::addDislikes()
{
    dislike_count++;
}

std::vector<int> Post::getLikedUsers()
{
    return liked_users;
}

std::vector<int> Post::getLaughs()
{
    return laughs;
}

std::vector<int> Post::getDislikes()
{
    return dislikes;
}

void Post::setLikedUsers(int id)
{
    liked_users.push_back(id);
}

void Post::setLaughs(int id)
{
    laughs.push_back(id);
}

void Post::setDislikes(int id)
{
    dislikes.push_back(id);
}

void Post::subtractLikes()
{
    likes_--;
}

void Post::subtractLaughs()
{
    laugh_count--;
}

void Post::subtractDislikes()
{
    dislike_count--;
}

void Post::remove_likes()
{
    liked_users.pop_back();
}

void Post::remove_laugh()
{
    laughs.pop_back();
}

void Post::remove_dislike()
{
    dislikes.pop_back();
}

int Post::getLaugh()
{
    return laugh_count;
}

int Post::getDislike()
{
    return dislike_count;
}

IncomingPost::IncomingPost(int messageId, int ownerId, std::string message, int likes, int laughs, int dislikes, std::vector<int> l_names, std::vector<int> la_names, std::vector<int> d_names, bool isPublic, std::string author)
    : Post(messageId, ownerId, message, likes, laughs, dislikes, l_names, la_names, d_names), isPublic_(isPublic), author_(author) {}

IncomingPost::IncomingPost()
    : Post(), isPublic_(true), author_("") {}

std::string IncomingPost::toString() 
{
    if (isPublic_ == true)
    {
        return author_ + " wrote: " + Post::toString(); 
    }
    else 
    {
        return author_ + " wrote (private): " + Post::toString(); 
    }   
}

std::string IncomingPost::getAuthor() const
{
    return author_;
}

bool IncomingPost::getIsPublic() const
{
    return isPublic_;
}
