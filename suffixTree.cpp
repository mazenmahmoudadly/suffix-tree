#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
   

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Push back adds a new element to the end of the list
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
      
    }

    // Begin returns an iterator pointing to the first element
    Node<T>* begin() const {
        return head;
    }

    // End returns an iterator pointing to one past the last element
    Node<T>* end() const {
        return nullptr;
    }
   
       void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Iterator for traversing the linked list
    class iterator {
    private:
        Node<T>* current;

    public:
        iterator(Node<T>* start) : current(start) {}

        T& operator*() {
            return current->data;
        }

        iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
        bool operator==(const iterator& other) const {
            return current == other.current;
        }
    };

    // Get an iterator pointing to the first element
    iterator begin() {
        return iterator(head);
    }

    // Get an iterator pointing to one past the last element
    iterator end() {
        return iterator(nullptr);
    }
};


using namespace std;

class TreeNode {
public:
    LinkedList<TreeNode*> children;
    int st;
    int id;

    TreeNode(int st, int id) : st(st), id(id) {}
};

class SuffixTree {
public:
    SuffixTree(const char* str) : str(str) {
        root = new TreeNode(-1, -1);
        int len = strlen(str);
        for (int i = len - 1; i >= 0; --i) {
            insertSuffix(root, i);
        }
    }

    void Search(const char* pattern) {
        LinkedList<int> results = searchPattern(root, pattern);
        results.reverse();
        
        if (results.begin() == results.end()) {
        cout << "not found";
    }
        for (int result : results) {
            cout << result << " ";
        }
        cout << endl;
    }

private:
    TreeNode* root;
    const char* str;

    void insertSuffix(TreeNode* node, int index) {
        TreeNode* current = node;
         int len = strlen(str);
        for (int i = index; i <len; ++i) {
            char c = str[i];
            auto it = findChild(current, c);

            if (it == current->children.end()) {
                TreeNode* newNode = new TreeNode(i, -1);
                current->children.push_back(newNode);
                current = newNode;
            } else {
                current = *it;
            }
        }

        current->id = index;
    }

    LinkedList<int> searchPattern(TreeNode* node, const char* pattern) {
        LinkedList<int> results;
        
        TreeNode* current = node;
   
        for (const char *ptr = pattern; *ptr != '\0'; ++ptr) {
            char c = *ptr;
        // Rest of your loop logic here
            auto it = findChild(current, c);

         if (it == current->children.end()) {
        return results;
                 }

                current = *it;
            }

        traverseSubtree(current, results);

        return results;
    }

    void traverseSubtree(TreeNode* node, LinkedList<int>& results) {
        if (node->id != -1) {
            results.push_back(node->id);
        }

        for (auto child : node->children) {
            traverseSubtree(child, results);
        }
    }

    LinkedList<TreeNode*>::iterator findChild(TreeNode* node, char c) {
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if (str[(*it)->st] == c) {
                return it;
            }
        }

        return node->children.end();
    }
};

int main() {
       cout<<"Test 1 \n";
//                 0123456789012
    SuffixTree t1("bananabanaba$");
    t1.Search("abann"); //not found
    t1.Search("aba"); // Prints: 5 9
    t1.Search("naba");// Prints: 4 8

    cout<<"\n\nTest 2: \n";
//                 012345678
    SuffixTree t2("dodohdoh$");
    t2.Search("dodo");// 0
    t2.Search("hdoh");// 4
    t2.Search("oh");// 3 6

    cout<<"\n\nTest 3: \n";
//                 0123456789012
    SuffixTree t3("havanabanana$");
    t3.Search("naxm"); // not found;
    t3.Search("ava");//1
    t3.Search("$");//12

    cout<<"\n\nTest 4: \n";
//                 01234567
    SuffixTree t4("aramarv$");
    t4.Search("rv$");//5
    t4.Search("ara$");//not found
    t4.Search("ma");//3

    cout<<"\n\nTest 5: \n";
//                 0123456789
    SuffixTree t5("cttattaac$");
    t5.Search("tta"); // 1 4
    t5.Search("tatt"); // 2
    t5.Search("at");//3

    cout<<"\n\nTest 6: \n";
//                 01234567890
    SuffixTree t6("abcdefghab$");
    t6.Search("ab"); // 0 8
    t6.Search("defghab$");//3
    t6.Search("abc"); // 0

    cout<<"\n\nTest 7: \n";
//                 01234567890
    SuffixTree t7("ttaagacatg$");
    t7.Search("gac"); // 4
    t7.Search("catg$");//6
    t7.Search("catg&"); // not found

    cout<<"\n\nTest 8: \n";
//                 0123456789012
    SuffixTree t8("abakanabakan$");
    t8.Search("e");//not found
    t8.Search("bak");// 1 7
    t8.Search("kan"); // 3 9;

    cout<<"\n\nTest 9: \n";
//                 0123456789
    SuffixTree t9("gtgatctcg$");
    t9.Search("tctc");//4
    t9.Search("gtg");//0
    t9.Search("t");// 1 4 6

    cout<<"\n\nTest 10: \n";
//                  012345678901
    SuffixTree t10("aacgcgcacg$");
    t10.Search("cg");// 8 4 2
    t10.Search("acg");// 7  1
    t10.Search("t"); // not found.


}
