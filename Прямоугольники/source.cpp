//
// Created by elena on 20.10.17.
//

#include <iostream>
using namespace std;

class Rectangle {
private:
    int height;
    int width;
public:
    Rectangle(int width_ = 0, int height_ = 0) :
            width(width_), height(height_) {
    }
    void increaseWidth(int addValue);
    void setHeight(int height) ;
    int getSquare() ;
    int getWidth();
    int getHeight();
    void setWidth(int width);
    Rectangle &operator = (const Rectangle & rectangle);

};



int Rectangle::getWidth() {
    return width;
}

int Rectangle:: getHeight() {
    return height;
}


void Rectangle:: setWidth(int width_) {
    width = width_;
}


void Rectangle::increaseWidth(int addValue)  {
    width += addValue;
}


void Rectangle::setHeight(int height_) {
    height = height_;
}

int Rectangle::getSquare()  {
    return width * height;
}

Rectangle & Rectangle::operator = (const Rectangle & rectangle) {
    if(this==&rectangle)
        return *this;
    width = rectangle.width;
    height = rectangle.height;
    return *this;
}

template <class T>
class Stack {
protected:
    T * information;
    int size;
    int amountOfelements;
public:
    Stack() : information(NULL), size(0), amountOfelements(0) { };
    void increaseSize();
    void push(T rectangle);
    bool isEmpty();
    T &pop(bool remove = true);
    T &lookLast();
    ~Stack();

};




template <class T>
void Stack<T> :: increaseSize()  {
    int newSize = 0;

    if (size > 0 )
        newSize = size * 2;
    else
        newSize = 5;

    T *newInformation = new T[newSize];

    if(amountOfelements > 0) {
        for(int i = 0; i < amountOfelements; i++) {
            newInformation[i] = information[i];
        }
    }

    information = newInformation;
    size = newSize;
}

template <class T>
T & Stack<T>::pop(bool rem) {
    if(rem) {
        return information[(amountOfelements--) - 1];
    }
    return information[amountOfelements - 1];
}

template <class T>
T & Stack<T>::lookLast()  {
    return pop(false);
}

template <class T>
void Stack<T>::push(T rectangle) {
    if(size == amountOfelements) {
        increaseSize();
    }
    information[amountOfelements] = rectangle;
    amountOfelements++;
}
template <class T>
bool Stack<T>::isEmpty() {
    return amountOfelements == 0;
}

template <class T>
Stack<T>::~Stack() {
    delete[] information;
}


int getMaxArea(Rectangle *rectangles, int amountOfrectangles) {

    Stack<Rectangle> st;
    st.push(rectangles[0]);

    int maxArea = rectangles[0].getSquare();


    for(int i = 1; i < amountOfrectangles; i++) {
        Rectangle *lastRectangle = &st.lookLast(), // получаем последний прямоугольник из стека
                *currentRectangle = &rectangles[i]; //прямоугольник на текущей итерации

        //если высота прямоугольника больше то отправляем его в стек
        if(currentRectangle->getHeight() >= lastRectangle->getHeight()) {
            st.push(*currentRectangle);
        }
        else
        {

            int lastRectangleHeight = lastRectangle->getHeight();//высота меньше чем у предыдущих прямоугольников


            //выталкиваем из стека прямоугольники до тех пор пока не встретим ниже или такой же по высоте
            while(lastRectangleHeight > currentRectangle->getHeight()) {
                        lastRectangle = &st.pop();


                        if(lastRectangle->getSquare() > maxArea) {// нашли прямоугольник у которого площадь больше
                            maxArea = lastRectangle->getSquare();
                        }
                        if(st.isEmpty()) { //стек оказался пуст: прямоугольников больше нет

                            // проверяем прямоугольник, сложенный с последним по высоте как текущий
                            lastRectangleHeight = currentRectangle->getHeight();
                            Rectangle rectangle1(lastRectangle->getWidth() + currentRectangle->getWidth(), (lastRectangleHeight = currentRectangle->getHeight()));
                            st.push(rectangle1);
                        }
                        else
                        {

                            st.lookLast().increaseWidth(lastRectangle->getWidth());
                            int followingHeight = st.lookLast().getHeight();//запоминаем высоту последнего элемента в стеке

                            if(followingHeight > currentRectangle->getHeight()) {
                               //если предыдущий элемент был выше текущего
                                lastRectangleHeight = followingHeight;
                            }
                            else if(followingHeight == currentRectangle->getHeight()) {
                                // высота предыдущего == высоте текущего
                                st.lookLast().increaseWidth(currentRectangle->getWidth());
                                lastRectangleHeight = currentRectangle->getHeight();
                            }
                            else
                            {
                                // если высота предыдущего ниже текущего
                                lastRectangleHeight = currentRectangle->getHeight();
                                Rectangle rectangle2(lastRectangle->getWidth() + currentRectangle->getWidth(), (lastRectangleHeight = currentRectangle->getHeight()));
                                st.push(rectangle2);
                            }
                        }



            }
        }
    }

    return maxArea;
}

int main() {
    int amountOfRectangles = 0;
    cin >> amountOfRectangles;
    amountOfRectangles++; // 0x0

    Rectangle *rectangles = new Rectangle[amountOfRectangles];

    for(int i = 0; i < amountOfRectangles - 1; i++) {
        int width = 0, height = 0;
        cin >> width;
        cin >> height;

        rectangles[i].setHeight(height);
        rectangles[i].setWidth(width);

    }

    rectangles[amountOfRectangles - 1].setWidth(0);

    int maxArea;
    maxArea=getMaxArea(rectangles, amountOfRectangles);
    cout<<maxArea<<endl;

    delete[] rectangles;

    return 0;
}