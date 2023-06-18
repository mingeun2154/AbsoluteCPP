/**
 * @file p7Classes.h
 * @brief CHAPTER14 project7
 * @author 2018203023 박민근
 * @date 2023-06-17
 */

#ifndef _P7_CLASSES_
#define _P7_CLASSES_

#include <string>

using namespace std;

namespace hw02 {

    namespace ch14 {
        
        class Document {

            public:
                Document(const string& content): text(content) {  }
                string getText() const { return text; }
                void setText(const string& content) { text = content; }
                Document& operator=(const Document& r) { text = r.getText(); return *this; }

            private:
                string text;
        }; // Document

        class Email: public Document {

            public:
                Email(const string& s, const string& r, const string& c)
                    : sender(s), recipient(r), Document(c) {  }
                string getsender() const { return sender; }
                string getRecipient() const { return recipient; }
                void setSender(const string& s) { sender = s; }
                void setRecipient(const string& r) { recipient = r; }
                Email& operator=(const Email& e) {
                    sender = e.getsender();
                    recipient = e.getRecipient();
                    this->setText(e.getText());
                    return *this;
                }

            private:
                string sender;
                string recipient;
        }; // Email


        class File: public Document {

            public:
                File(const string& p,
                    const string& content)
                    : path(p), Document(content) {  }
                string getPath() const { return path; }
                void setPath(const string& p) { path = p; }
                File& operator=(const File& f) {
                    path = f.getPath();
                    this->setText(f.getText());
                    return *this;
                }

            private:
                string path;
            
        }; // File


    } // ch14
    
} // hw02


#endif // _P7_CLASSES_
