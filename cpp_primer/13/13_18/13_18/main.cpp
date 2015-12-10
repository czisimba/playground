//
//  main.cpp
//  13_18
//
//  Created by nichola on 15/11/27.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace::std;
class Folder;


class Message {
    friend Folder;
public:
    Message(const string &s = ""):content(s) {
    }
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void show();
private:
    void addFolder(Folder * const );
    void removeFolder(Folder * const );
    void Put_Msg_In_Folders(const set<Folder *> &);
    void Remove_Msg_From_Folders();
    string content;
    set<Folder *> Folders;
};

class Folder {
    friend Message;
public:
    ~Folder();
private:
    void addMsg(Message *);
    void removeMsg(Message *);
    set<Message *> Messages;
    void Remove_Folders_From_Msgs();
};
Folder::~Folder() {
    Remove_Folders_From_Msgs();
}
void Folder::addMsg(Message *m) {
    Messages.insert(m);
}
void Folder::removeMsg(Message *m) {
    Messages.erase(m);
}
void Folder::Remove_Folders_From_Msgs()
{
    // remove folder from messages
    for (set<Message *>::const_iterator iter = Messages.begin(); iter != Messages.end(); ++iter)
    {
        (*iter)->removeFolder(this);
    }
}

Message::Message(const Message &m):content(m.content),Folders(m.Folders) {
    Put_Msg_In_Folders(Folders);
}
Message &Message::operator=(const Message &m) {
    if (&m != this)
    {
        Remove_Msg_From_Folders();
        content = m.content;
        Folders = m.Folders;
        Put_Msg_In_Folders(m.Folders);
    }
    return *this;
}
Message::~Message() {
    Remove_Msg_From_Folders();
}

void Message::save(Folder &f) {
    addFolder(&f);
    f.addMsg(this); // put message to Folder
}
void Message::remove(Folder &f) {
    removeFolder(&f);
    f.removeMsg(this); // put message to Folder
}
void Message::show() {
    cout << "message pointer:" << this << endl;
    
    for (set<Folder *>::const_iterator iter = Folders.begin(); iter != Folders.end(); ++iter) {
        cout << "        folders pointer:" << *iter << endl;
        for (set<Message *>::const_iterator iter1 = (*iter)->Messages.begin(); iter1 != (*iter)->Messages.end(); ++iter1) {
            cout << "                folder message pointer:" << *iter1 << endl;
        }
    }
}
void Message::addFolder(Folder * const fp) {
    Folders.insert(fp);
}

void Message::removeFolder(Folder * const fp) {
    Folders.erase(fp);
}
void Message::Put_Msg_In_Folders(const set<Folder *> &fs)
{
    // put message to Folders
    for (set<Folder *>::const_iterator iter = fs.begin(); iter != fs.end(); ++iter)
    {
        (*iter)->addMsg(this);
    }
}
void Message::Remove_Msg_From_Folders()
{
    // remove message from folders
    for (set<Folder *>::const_iterator iter = Folders.begin(); iter != Folders.end(); ++iter)
    {
        (*iter)->removeMsg(this);
    }
}

int main()
{
    Message msg0;
    Message msg1;
    Folder fd0;
    Folder fd1;
    msg0.save(fd0);
    msg0.save(fd1);
    msg1.save(fd0);
    msg1.save(fd1);
    msg0.show();
    msg1.show();
    
    
    return 0;
}
