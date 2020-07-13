#include "mainwindow.h"

#include <QApplication>


#include <QtWidgets>
#include <QLayout>

#include <QList>
#include <QPushButton>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
using namespace std;
#include <QTextStream>
void create(bool** s, int w, int h, int n, int x, int y)
{
    srand(static_cast<unsigned int>(time(0)));
    int l = 0;
    //double b = 0;
    //создаю масси
    for (int i = 0; i < w + 1; i++)
        s[i] = new bool[h + 1];
    //заполняю нулями
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            s[i][j] = 0;
    //цикл, пока кол-во бомб не будт равно переданному
    while (l < n)
    {
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                //b = rand() % 100;
                //if (b > 95)

                //ставлю 1, если сейчас там еще нет бомбы и если игрок не бырал эту клетку
                if (/*b > 95 and*/ l < n and s[i][j] == 0 and x - 1 != i and y - 1 != j)
                {
                    if (rand() % 100 > 97)
                    {
                        s[i][j] = 1;
                        l++;
                    }
                }
            }
        }
    }
}
void check(bool** s1, QPushButton **mass, int w, int h, int x, int y, string c)
{
    int n = 0;

    if (c == "o" or c == "O")
    {
        if (s1[x][y] == 1)
        {
            cout << "YOU LOSE!" << endl;
            //outlose(s1, s2, w + 1, h + 1);
            exit(1);
        }
        mass[x][y].setText("c");
        //right
        if (y < h )
        {
            if (s1[x][y + 1] == 1 and mass[x ][y+1].text() == "")
                n++;
            /*else if (s1[x][y + 1] == 0 and s2[x+1][y + 2] == "|_|" and s2[x + 1][y + 1] == "|0|")//rigth
                cheek(s1, s2, w, h, x, y + 1, c);*/
        }
        //up
        if (x > 0 )
        {
            if (s1[x - 1][y] == 1 and mass[x-1][y].text() == "")
                n++;
            /*else if (s1[x - 1][y] == 0 and s2[x][y+1] == "|_|")//up

                cheek(s1, s2, w, h, x - 1, y, c);*/
        }
        //down
        if (x < w)
        {
            if (s1[x + 1][y] == 1 and mass[x+1][y].text() == "")
                n++;
            /*else if (s1[x + 1][y] == 0 and s2[x+2][y + 1] == "|_|")//down
                cheek(s1, s2, w, h, x + 1, y, c);*/
        }
        //left
        if (y > 0 )
        {
            if (s1[x][y - 1] == 1 and mass[x][y].text() == "")
                n++;
            /*else if (s1[x][y - 1] == 0 and s2[x+1][y] == "|_|")
                cheek(s1, s2, w, h, x, y - 1, c);*/
        }
        //down left
        if (x < w and y > 0)
        {
            if (s1[x + 1][y - 1] == 1)
                n++;

        }
        //down right
        if (x < w and y < h)
        {
            if (s1[x + 1][y + 1] == 1)
                n++;

        }
        //up right
        if (x > 0 and y < h)
        {
            if (s1[x - 1][y + 1] == 1)
                n++;

        }
        //up left
        if (x > 0 and y > 0)
        {
            if (s1[x - 1][y - 1] == 1)
                n++;

        }

        stringstream ss;
        ss << n;
        string n1 = ss.str();
        QString str = QString::fromStdString(n1);
        mass[x ][y ].setText(str);

/*
        //rigth
        if (y < h)
            if (s1[x][y + 1] == 0 and s2[x + 1][y + 2] == "|_|" and (s2[x + 1][y + 1] == "|0|" or s2[x][y + 1] == "|0|" or s2[x + 2][y + 1] == "|0|"))
                check(s1, s2, w, h, x, y + 1, c);
        //up
        if (x > 0)
            if (s1[x - 1][y] == 0 and s2[x][y + 1] == "|_|" and (s2[x + 1][y + 1] == "|0|" or s2[x + 1][y] == "|0|" or s2[x + 1][y + 2] == "|0|"))
                check(s1, s2, w, h, x - 1, y, c);
        //down
        if (x < w)
            if (s1[x + 1][y] == 0 and s2[x + 2][y + 1] == "|_|" and (s2[x + 1][y + 1] == "|0|" or s2[x + 1][y] == "|0|" or s2[x + 1][y + 2] == "|0|"))
                check(s1, s2, w, h, x + 1, y, c);
        //left
        if (y > 0)
            if (s1[x][y - 1] == 0 and s2[x + 1][y] == "|_|" and (s2[x + 1][y + 1] == "|0|" or s2[x][y + 1] == "|0|" or s2[x + 2][y + 1] == "|0|"))
                check(s1, s2, w, h, x, y - 1, c);
                */
    }
    else if (c == "c" or c == "C")
        mass[x ][y ].setText("!");
    else if (c == "u" or c == "U")
        mass[x ][y ].setText("");

}
class MyClass : public QObject {

    Q_OBJECT

    public:
        MyClass();

    public slots:
        void MyFunc();

};


void MyClass::MyFunc() {

    cout<<( "111f" )<<endl;

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    int n = 10;

    //QLabel *l=new QLabel("");
    QVector<QVBoxLayout*> col;
    QPushButton *mass[n][n];
    int x=5;
    int y=5;

    for(int i = 0; i < n; i++)
    {
        QVBoxLayout *Col1 = new QVBoxLayout();
        col.append(Col1);

        for(int j = 0; j < n; j++)
        {
            QPushButton *b = new QPushButton("");
            b->setFixedSize(30,30);

            mass[i][j]=b;
            QObject::connect(mass[i][j],SIGNAL( clicked() ),&w,SLOT( myClass->MyFunc() ));

            col[i]->addWidget(b/*,Qt::AlignTop | Qt::AlignLeft*/);

        }
    }
    QHBoxLayout *line1 = new QHBoxLayout();
    for(int i = 0; i < n; i++)
    {
        line1->addLayout(col[i]);
    }

    w.setLayout(line1);
    w.show();
    bool** s1 = new bool* [n];
    thread tC1(create, s1, n, n, n, x, y);
    tC1.join();
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {                
                cout << s1[i][j];
            }
            cout << endl;
        }
    QObject::connect(mass[x][y],SIGNAL( clicked() ),&w,SLOT( myClass->MyFunc() ));

    //check(s1, *mass, n-1, n-1, x - 1, y - 1, "o");
    /*bool** s1 = new bool* [n+1];
    int x = 0;
    while (x > n or x < 1)
    {
        cout << "enter y" << endl;
        cin >> x;
    }
    int y = 0;
    while (y > n or y < 1)
    {
        cout << "enter x" << endl;
        cin >> y;
    }
    thread tC1(create, s1, n, n, n, x, y);
    tC1.join();
    check(s1, **mass, n, n, x - 1, y - 1, "o");*/

    return a.exec();




}
