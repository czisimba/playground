//
//  main.cpp
//  13_17
//
//  Created by nichola on 15/11/27.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace::std;
class Message;
class Folder {
public:
    void addMsg(Message *);
    void removeMsg(Message *);
private:
    set<Message *> Messages;
};

class Message {
public:
    Message(const string &s = ""):content(s) {
    }
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
private:
    void addFolder(Folder * const );
    void removeFolder(Folder * const );
    void Put_Msg_In_Folders(const set<Folder *> &);
    void Remove_Msg_From_Folders();
    string content;
    set<Folder *> Folders;
};

void Folder::addMsg(Message *m) {
    Messages.insert(m);
}
void Folder::removeMsg(Message *m) {
    Messages.erase(m);
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
    Message msg;
    
    cout << "show message!" << endl;
    
    return 0;
}
