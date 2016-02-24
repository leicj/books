#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Folder;

class Message{
    friend class Folder;
    friend ostream &operator<<(ostream &os, const Message &msg);
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const string &str = "") :
        contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    // 从给定folder中添加/删除本Message
    void save(Folder &);
    void remove(Folder &);
private:
    string contents;    // 实际消息文本
    set<Folder*> folders;   //包含本消息的folder
    // 拷贝构造函数，拷贝赋值运算符和析构函数所使用的工具
    void add_to_folders(const Message&);
    void remove_from_folders();
};
class Folder{
    friend ostream &operator<<(ostream &os, const Folder &folders);
public:
    Folder(const string &s = string()) :
        name(s){}
    void addMsg(Message *m)
    {
        msgs.insert(m);
    }
    void remMsg(Message *m)
    {
        msgs.erase(m);
    }
private:
    set<Message *> msgs;
    string name;
};

ostream &operator<<(ostream &os, const Message &msg)
{
    os << msg.contents << " ";
    return os;
}
void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message &m)
{
    set<Folder *>::iterator beg = m.folders.begin();
    for (; beg != m.folders.end(); ++beg) {
       (*beg)->addMsg(this);
    }
}

Message::Message(const Message &m) :
    contents(m.contents), folders(m.folders)
{
    add_to_folders(m);
}

void Message::remove_from_folders()
{
    set<Folder *>::iterator beg = folders.begin();
    for (; beg != folders.end(); beg++) {
        (*beg)->remMsg(this);
    }
}

Message::~Message()
{
    remove_from_folders();
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    set<Folder *>::iterator beg = lhs.folders.begin();
    for (; beg != lhs.folders.end(); beg++) {
        (*beg)->remMsg(&lhs);
    }
    beg = rhs.folders.begin();
    for (; beg != rhs.folders.end(); beg++) {
        (*beg)->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
   // swap(lhs.contents, rhs.contents);
    beg = lhs.folders.begin();
    for (; beg != lhs.folders.end(); beg++) {
        (*beg)->addMsg(&lhs);
    }
    beg = rhs.folders.begin();
    for (; beg != rhs.folders.end(); beg++) {
        (*beg)->addMsg(&rhs);
    }
}


ostream &operator<<(ostream &os, const Folder &folders)
{
    os << folders.name << ":\n";
    set<Message *>::iterator beg = folders.msgs.begin();
    for (; beg != folders.msgs.end(); ++beg) {
        os << **beg;
    }
    return os;
}

int main(void)
{
    Folder folder1("folder1");
    Folder folder2("folder2");
    Message msg1("message1");
    Message msg2("message2");
    Message msg3("message3");
    Message msg4("message4");
    Message msg5("message5");
    Message msg6("message6");
    Message msg7("message7");
    Message msg8("message8");

    msg1.save(folder1);
    msg2.save(folder1);
    msg3.save(folder1);
    msg4.save(folder1);
    msg5.save(folder1);
    cout << folder1 << endl;
    msg4.save(folder2);
    msg5.save(folder2);
    msg6.save(folder2);
    msg7.save(folder2);
    msg8.save(folder2);
    cout << folder2 << endl;

    msg1.remove(folder1);
    msg4.remove(folder2);
    cout << folder1 << endl;
    cout << folder2 << endl;

    swap(msg2, msg6);
    cout << folder1 << endl;
    cout << folder2 << endl;


    return 0;
}
