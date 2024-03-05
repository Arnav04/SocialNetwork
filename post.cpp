#include <fstream>
#include <iostream>
#include <sstream>

#include "post.h"

Post::Post(int messageId, int ownerId, std::string message, int likes) : messageId_(messageId), ownerId_(ownerId), message_(message), likes_(likes) {}

Post::Post()
{
    messageId_ = 0; 
    ownerId_ = 0;
    message_ = "";
    likes_ = 0;
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

IncomingPost::IncomingPost(int messageId, int ownerId, std::string message, int likes, bool isPublic, std::string author) 
    : Post(messageId, ownerId, message, likes), isPublic_(isPublic), author_(author) {}

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