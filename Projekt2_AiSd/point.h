#ifndef POINT_H
#define POINT_H

//using namespace std;

class point {
private:
    int x, y;

public:
    point()
    {
        this->x = 0;
        this->y = 0;
    }

    /* point(p) {
         this->x = a.x;
         this->y = a.y;
     }*/

    point(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
    int getX(void)
    {
        return this->x;
    }
    int getY(void)
    {
        return this->y;
    }
    void setX(int x) {
        this->x = x; 
    }
    void setY(int y) {
        this->y = y;
    }
    bool operator==(const point& other) {
        return (x == other.x && y == other.y);
    }
    friend ostream& operator<< (ostream& out, const point& obj) {
        out << obj.x << " " << obj.y;
        return out;
    }
};

#endif