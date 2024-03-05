#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm> // inclusion for std::sort, https://cplusplus.com/reference/algorithm/sort/

#include "network.h"

Network::Network() {}

int Network::readUsers(const char* fileName) 
{
    std::ifstream file(fileName);

    std::string line;
    
    if (!file.is_open() || !file) 
    {
        return -1;
    }

    int users;

    file >> users;
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        
        int id = std::stoi(line);
        std::getline(file, line); 
        std::string name = line.substr(1);
        std::getline(file, line); 
        int year = std::stoi(line);
        std::getline(file, line);  
        int zip = std::stoi(line);

        std::getline(file, line); 
        std::stringstream val(line);
        std::set<int> friends;  
        int s;
            
        while (val >> s) 
        {
            friends.insert(s);
        }

        User* u = new User(id, name, year, zip, friends);
        addUser(u); 
    }

    file.close();
    return 0;
}


int Network::writeUsers(const char* fileName) 
{
    std::ofstream file(fileName);
    if (!file.is_open()) 
    {
        return -1;
    }
    file << users.size() << "\n";
    for (std::size_t i = 0; i < users.size(); i++) 
    {
        file << users[i]->getId() << std::endl;
        file << "\t" << users[i]->getName() << std::endl;
        file << "\t" << users[i]->getYear() << std::endl;
        file << "\t" << users[i]->getZip() << std::endl;
        std::set<int> friends = users[i]->getFriends();
        file << "\t";
        for (auto f : friends) 
        {
            file << f << " ";
        }
        file << std::endl;
    }
    file.close();
    return 0;
}



int Network::addConnection(const std::string s1, const std::string s2)
{
    int one = getId(s1);
    int two = getId(s2);

    if (one == two || one == -1 || two == -1)
    {
        return -1;
    }
    else
    {
        User* u1 = getUser(one);
        User* u2 = getUser(two);

        u1->addFriend(two);
        u2->addFriend(one);
        return 0;
    }
}

int Network::deleteConnection(const std::string s1, const std::string s2)
{
    int one = getId(s1);
    int two = getId(s2);

    if (one == two)
    {
        return -1;
    }
    else
    {
        User* u1 = getUser(one);
        User* u2 = getUser(two);

        std::set<int> friends = u1->getFriends();

        bool stat = false;

        auto iter = friends.find(two);
        if (iter != friends.end()){
            stat = true;
        }

        if (stat == false)
        {
            return -1;
        }
        else
        {
            u1->deleteFriend(two);
            u2->deleteFriend(one);
            return 0;

        }
    }
}

void Network::addUser(User* u)
{
    users.push_back(u);
}

int Network::getId(const std::string& name) 
{
    for (std::size_t i = 0; i < users.size(); i++) 
    {
        if (users[i]->getName() == name) 
        {
            return users[i]->getId();
        }
    }
    return -1;
}

User* Network::getUser(int id)
{
    for (auto* u : users)
    {
        if (u->getId() == id)
        {
            return u;
        }
    }
    return nullptr;
}

int Network::numUsers() const
{
    return users.size();
}

void Network::printUsers()
{
    for (auto* u : users)
    {
        std::cout << u->getId() << " " << u->getName() << std::endl;
    }
}

void Network::printFriends(std::string& name)
{
    for (auto* u : users)
    {
        if (u->getName() == name)
        {
            for (auto f : u->getFriends())
            {
                if (getUser(f) != nullptr)
                {
                    std::cout << getUser(f)->getId() << " " << getUser(f)->getName() << std::endl;
                }
            }
        }  
    }
}

std::vector<int> Network::shortestPath(int from, int to)
{
    std::queue<int> q;
    std::vector<bool> visited (users.size(), 0);
    std::vector<int> path(users.size(), -1);
    std::vector<int> shortest_path;
    shortest_path.push_back(to);

    if (getUser(from) == nullptr || getUser(to) == nullptr)
    {
        std::cout << "None" << std::endl;
        return std::vector<int> {};
    }

    if (to == from)
    {
        return shortest_path;
    }

    visited[from] = true;
    q.push(from);

    while (q.size() > 0) 
    {
        int cur = q.front();
        User* u = getUser(cur);
        q.pop();

        for (auto neighbor : u->getFriends())
        {
            if (!visited[neighbor])
            {
                path[neighbor] = cur; // each neighbor index in path has cur value to indicate the predecessors of neighbors in path are cur
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    int curr = to;
    if (path[to] == -1)
    {
        std::cout << "None" << std::endl;
        return shortest_path;
    }

    while (path[curr] != -1)
    {
        shortest_path.push_back(path[curr]);
        curr = path[curr];
    }

    std::reverse(shortest_path.begin(), shortest_path.end()); 
    return shortest_path;
}



std::vector<int> Network::distanceUser(int from, int& to, int distance)
{
    std::queue<int> q;
    std::vector<bool> visited (users.size(), 0);
    std::vector<int> path(users.size(), -1);

    std::vector<int> p;

    if (getUser(from) == nullptr)
    {
        to = -1;
        return std::vector<int> {};
    }

    if (distance == 0)
    {
        p.push_back(from);
        return p;
    }

    visited[from] = true;
    q.push(from);

    int d = 0;

    to = -1;

    while (q.size() > 0 && d < distance) 
    {
        int level_count = q.size();
        for (int i = 0; i < level_count; i++)
        {
            int cur = q.front();
            User* u = getUser(cur);
            q.pop();

            for (auto neighbor : u->getFriends())
            {
                if (!visited[neighbor])
                {
                    path[neighbor] = cur; // each neighbor index in path has cur value to indicate the predecessors of neighbors in path are cur
                    visited[neighbor] = true;
                    q.push(neighbor);
                    if (d + 1 == distance)
                    {
                        to = neighbor;
                    }
                }
            }
        }
        d++;
    }

    if (path[to] == -1 || to == -1)
    {
        to = -1; 
        return std::vector<int> {};
    }

    p.push_back(to);

    int curr = to;
    while (path[curr] != -1)
    {
        p.push_back(path[curr]);
        curr = path[curr];
        d++;
    }
    std::reverse(p.begin(), p.end()); 
    return p;
}

std::vector<int> Network::suggestFriends(int who, int& score)
{
    std::queue<int> q;
    std::unordered_map<int, int> count;
    std::vector<bool> visited (users.size(), 0);
    std::vector<int> suggestions;

    if (getUser(who) == nullptr)
    {
         return std::vector<int> {};
    }

    visited[who] = true;
    q.push(who);

    int d = 0;

    std::set<int> og_friends = getUser(who)->getFriends();
    while (q.size() > 0 && d <= 2) 
    {
        int level_count = q.size();
        for (int i = 0; i < level_count; i++)
        {
            int cur = q.front();
            User* u = getUser(cur);
            q.pop();

            for (auto neighbor : u->getFriends())
            {
                if (d > 0)
                {
                    if (og_friends.count(neighbor) == 1)
                    {
                        count[cur]++;
                    }
                }
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        d++;
    }

    int max = 0;
    for (auto val : count)
    {
        if (val.second > max)
        {
            max = val.second;
        }
    }
    score = max;

    for (auto val : count)
    {
        if (val.second == max)
        {
            suggestions.push_back(val.first);
        }
    }

    if (suggestions.size() == 0)
    {
        score = 0;
        return std::vector<int> {};
    }

    return suggestions;
}

std::vector<std::vector<int>> Network::groups()
{
    std::vector<std::vector<int>> output;
    std::vector<bool> visited(users.size(), 0);

    for (auto* user : users)
    {
        if (!visited[user->getId()])
        {
            std::stack<int> stck;
            std::vector<int> curr;
            stck.push(user->getId());
            visited[user->getId()] = true;

            while (stck.size() > 0)
            {
                int cur = stck.top();
                User* u = getUser(cur);
                stck.pop();
                curr.push_back(cur);

                for (auto neighbor : u->getFriends())
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        stck.push(neighbor);
                    }
                } 
            }
            output.push_back(curr);
        }
    }
    return output;
}

void Network::addPost(int ownerId, std::string message, int likes, bool isIncoming, std::string authorName, bool isPublic)
{
    int messageId = 0;

    for (auto* u : users)
    {
        if (!u->getPosts().empty())
        {
            for (auto* p : u->getPosts())
            {
                messageId++;
            }
        }
    }

    if (isIncoming == false)
    {
        getUser(ownerId)->addPost(new Post(messageId, ownerId, message, likes));
    }
    else
    {
        getUser(ownerId)->addPost(new IncomingPost(messageId, ownerId, message, likes, isPublic, authorName));
    }
    
}

std::string Network::getPostsString(int ownerId, int howMany, bool showOnlyPublic)
{
    User* u = getUser(ownerId);
    return u->getPostsString(howMany, showOnlyPublic);
}

int Network::readPosts(const char* fname)
{
    std::ifstream file(fname);

    if (!file.is_open()) 
    {
        return -1;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        int messageId = std::stoi(line);
        std::getline(file, line); 
        std::string message = line.substr(1);
        std::getline(file, line); 
        int ownerId = std::stoi(line);
        std::getline(file, line); 
        int likes = std::stoi(line);
        std::getline(file, line); 
        std::string isPublic;
        if (line != "")
        {
            isPublic = line.substr(1);
        }
        else
        {
            isPublic = line;
        }
        std::getline(file, line); 
        std::string author;
        if (line != "")
        {
            author = line.substr(1);
        }
        else
        {
            author = line;
        }
        if (author == "" && isPublic == "")
        {
            Post* p = new Post(messageId, ownerId, message, likes);
            User* u = getUser(ownerId);
            u->addPost(p);
        }
        else
        {
            User* u = getUser(ownerId);
            if (isPublic == "public")
            {
                IncomingPost* p = new IncomingPost(messageId, ownerId, message, likes, true, author);
                u->addPost(p);
            }
            else
            {
                IncomingPost* p = new IncomingPost(messageId, ownerId, message, likes, false, author);
                u->addPost(p);
            }
        }            
    }

    return 0;
}

int Network::writePosts(const char* fname)
{
    std::ofstream file(fname);
    if (!file.is_open()) 
    {
        return -1;
    }

    std::vector<Post*> posts;
    for (auto* u : users)
    {
        for (auto* p : u->getPosts())
        {
            posts.push_back(p);
        }
    }

    std::sort(posts.begin(), posts.end(), comparisonFunc);

    file << posts.size() << std::endl;
    for (std::size_t i = 0; i < posts.size(); i++)
    {
        file << posts[i]->getMessageId() << std::endl;
        file << "\t" << posts[i]->getMessage() << std::endl;
        file << "\t" << posts[i]->getOwnerId() << std::endl;
        file << "\t" << posts[i]->getLikes() << std::endl;
        if (posts[i]->getAuthor() == "")
        {
            file << "" << std::endl;
        }  
        else
        {
            if (posts[i]->getIsPublic() == true)
            {
                file << "\t" << "public" << std::endl;
            } 
            else
            {
                file << "\t" << "private" << std::endl;
            }
        }     
        file << "\t" << posts[i]->getAuthor() << std::endl; 
    }
    file.close();
    return 0;
}

bool Network::comparisonFunc(Post* p1, Post* p2)
{
    return p1->getMessageId() < p2->getMessageId();
}
