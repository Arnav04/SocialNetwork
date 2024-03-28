#include "user.h"

User::User(int id, const std::string& name, int yr, int zip, const std::set<int>& friends)
    : id(id), name(name), yr(yr), zip(zip), friends(friends) {}

User::User() : id(0), name(""), yr(0), zip(0) {}

int User::getId() const 
{
    return id;
}

std::string User::getName() const
{
    return name;
}

int User::getYear() const
{
    return yr;
}

int User::getZip() const
{
    return zip;
}

std::set<int>& User::getFriends() 
{
    return friends;
}

void User::addFriend(int friendId)
{
    friends.insert(friendId);
}

void User::deleteFriend(int friendId) 
{
    auto iter = friends.find(friendId);
    if (iter != friends.end()){
        friends.erase(iter);
    }
}

void User::addPost(Post* p)
{
    messages_.push_back(p);
}

std::vector<Post*> User::getPosts()
{
    return messages_;
}

std::string User::getPostsString(int howMany, bool showOnlyPublic)
{
    std::string output = "";
    int j = messages_.size() - 1;
    int i = 0;
    while (i < howMany && j >= 0)
    {
        if (showOnlyPublic == false)
        {
            output += messages_[j]->toString() + "\n";
            i++;
        }
        else if (showOnlyPublic == true)
        {
            if (messages_[j]->getIsPublic() == true)
            {
                output += messages_[j]->toString() + "\n";
                i++;
            }
        }
        j--;
    }   
    return output;
}

std::vector<Post*> User::getPublicMessages()
{
    std::vector<Post*> public_messages;
    for (size_t i = 0; i < messages_.size(); i++)
    {
        if (messages_[i]->getIsPublic() == true)
        {
            public_messages.push_back(messages_[i]);
        }
    }
    return public_messages;
}
