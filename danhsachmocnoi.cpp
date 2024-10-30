#include<iostream>

using namespace std;

// Khai bao cau truc cho mot phan tu cua da thuc
struct Node {
    float heso;
    int somu;
    Node *next;

    Node(float hs, int sm) : heso(hs), somu(sm), next(nullptr){}
};

// Lop da thuc
class Dathuc {
    private:
        Node *head; //con tro dau danh sach
    public:
        Dathuc() : head(nullptr) {} 

    //ham de them 1 phan tu
    void Them(float heso, int somu) {
        if(heso==0) return;

        Node* newNode = new Node(heso, somu);

        //them vao dau danh sach
        if(!head || head->somu < somu) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* newhead = head;
            while(newhead->next && newhead->next->somu > somu) {
                newhead = newhead->next;
            }
            newNode->next = newhead->next;
            newhead->next = newNode;
        }
    }

//hamin dathuc
void inDathuc() {
    if(!head) {
        cout<<"0"<< endl;
        return;
    }

    Node* newhead = head;
    while(newhead) {
        if(newhead->heso>0 && newhead != head)
            cout<< "+" ;
        if(newhead->somu==0) 
            cout<< newhead->heso;
            else if(newhead->somu == 1) cout <<newhead->heso<< "x";
            else cout<<newhead->heso << "x^" <<newhead->somu;
            newhead=newhead->next;
    }
    cout<<endl;
}

//giaiphong bo nho
~Dathuc() {
    Node* newhead = head;
    while(newhead) {
        Node* temp = newhead;
        newhead = newhead->next;
        delete temp;
    }
  }
};

int main() {
    Dathuc DT;

    float heso;
    int somu;

    cout<<"Nhap he so: ";
    cin >> heso;
    cout<<"Nhap so mu: ";
    cin>> somu;

    DT.Them(heso, somu);
    cout<<"Da thuc la: y= ";
    DT.inDathuc();

    return 0;
}

