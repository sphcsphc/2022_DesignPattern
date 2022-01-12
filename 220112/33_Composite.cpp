#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
protected:
    string name;
public:
    Item() {}
    virtual int GetSize() {}
};

class File : public Item {
    int size;
public:
    File(string name, int size) {
        this->name = name;
        this->size = size;
    }
    int GetSize() override { return size }
};

class Folder : public Item {
public:
    Folder(string name) {
        this->name = name;
    }
    void AddItem(File* f) {
        
    }
    int GetSize() override { return size }
};

int main()
{
    Folder* fol1 = new Folder("ROOT");
    Folder* fol2 = new Folder("A");

    File* f1 = new File("a.txt", 10); // 이름, 크기
    File* f2 = new File("b.txt", 20);

    fol2->AddItem(f1);
    fol1->AddItem(f2);
    fol1->addItem(fol2);
    cout << f2->GetSize() << endl;
    cout << fol2->GetSize() << endl;
    cout << fol1->GetSize() << endl;
}