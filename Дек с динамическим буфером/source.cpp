//
// Created by elena on 29.09.17.
//
#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;
class Deque{
public:
    explicit Deque(const size_t &);
    Deque(int size);
    ~Deque(){ delete [] buffer;}
    bool isEmpty() const { return head == tail; }
    void PushBack(int a);
    void PushFront(int a);
    int PopBack();
    int PopFront();
    void grow();
    size_t buffer_grow() const {
        assert(bufferSize > 0);
        return bufferSize * 2;
    }
private:
    int *buffer;
    int bufferSize;
    int head;//указатель на первый элемент очереди
    int tail;//указывает на следующий после последнего

};

void cpy(const int *const src,
         const size_t &src_head_idx,
         const size_t &src_tail_idx,
         const size_t &src_size,
         int *const dst) {
    size_t dst_idx = 0;
    for (size_t src_idx = src_head_idx; src_idx != src_tail_idx;) {
        dst[dst_idx] = src[src_idx];

        ++dst_idx;
        ++src_idx;
        src_idx %= src_size;
    }
}

void Deque::grow() {
    int *temp_array = new int[buffer_grow()];

    if (temp_array != NULL) {
        cpy(buffer, head, tail, bufferSize, temp_array);

        head = 0;
        tail= bufferSize - 1;

        bufferSize = buffer_grow();

        delete[] buffer;
        buffer = temp_array;
    }
}



Deque::Deque( int size):
    bufferSize(size),
    head(0),
    tail(0)
{
    buffer=new int[bufferSize];//создаем буфер
}
//Извлечение элемента с конца
int Deque::PopBack() {
    if(isEmpty())
        return -1;
    if (tail<1)
        tail+=bufferSize;

    int result=buffer[(--tail)%bufferSize];/// отрицательный индекс может получиться
   // cout<<"head="<<tail<<"\n";
    return result;
}

//Добавление элемента в начало списка
void Deque::PushFront( int a){
    if((tail+1)%bufferSize == head) {
        grow();
    }
    if (head<1){
        head+=bufferSize;
    }
    buffer[(--head)%bufferSize] = a;
   // cout<<"head="<<head<<"\n";
}




//Добавление элемента в конец
void Deque::PushBack( int a) {
    if((tail+1)%bufferSize == head) {
        grow();
    }
    buffer[(tail++)%bufferSize] = a;
    //tail%=bufferSize;

    //cout<<"tail="<<tail<<"\n";

}

//Извлечение элемента из головы
int Deque::PopFront() {
    if(isEmpty() || (head==bufferSize && tail==-1))
        return -1;
    int result = buffer[(head++)%bufferSize];
    return result;
}

int main(){
    int n = 0;
    cin >> n;
    assert(n<=1000000 && n>0);
    Deque deque(n);
    int command = 0;
    int value = 0;
    bool flag=false;
    for(int i=0; i<n; i++) {
        cin>>command;
        cin>>value;
        switch(command){
            case 1:
                deque.PushFront(value);
                break;
            case 2:
                int res1;
                res1=deque.PopFront();
                if (value !=res1) {
                    flag = true;
                  //  cout<<"NO 2:"<<value<<" "<<res1<<"\n";
                }
                break;
            case 3:
                deque.PushBack(value);
                break;
            case 4:
                int res;
                res=deque.PopBack();
                if(value!=res) {
                    flag = true;
                  //  cout<<"NO 4:"<<value<<" "<<res<<" \n";
                }
                break;
            default:
                assert(false);
        }
    }
    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
}