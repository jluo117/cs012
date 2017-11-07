#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
using namespace std;

class Message {
 protected:
    vector<Message *> childList;
    string author;
    string subject;
    string body;
    unsigned id;
 public:
    // default constructor
    Message();
    Message(const string &athr, const string &sbjct,const string &bd,unsigned id);

   virtual ~Message();
   virtual bool isReply() const = 0;
   virtual string toFormattedString() const = 0;
   void print(unsigned indentation) const; // New !!
	 /* This function is responsible for printing the Message
      * (whether Topic or Reply), and and all of the Message's
      * "subtree" recursively:
      * After printing the Message with indentation n and appropriate
      * format (see output details), it will invoke itself
      * recursively on all of the Replies in its childList,
      * incrementing the indentation value at each new level.
      *
      * Note: Each indentation increment represents 2 spaces. e.g. if
      * indentation == 1, the reply should be indented 2 spaces, if
      * it's 2, indent by 4 spaces, etc.
      */

    // Constructor with parameters

    // Displays the message in the given format. See output specs.
    // Note: this function must output a single newline character
    // at the end (after the body).
     const string & getSubject() const;
    void display() const;
    unsigned getID() const;
    void addChild(Message *child);
private:
    void spacing(unsigned totalSpc) const;


};
#endif
