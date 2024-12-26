// Interface.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

class Drawable // abstraite si virtuel pur, si virtuel pur, pas instanciable
{
    virtual void draw() const = 0; // méthode virtuel pure
};


class Shape : public Drawable
{
public :
    Shape(float X, float Y) : x(X), y(Y){}
    void draw() const
    {
        std::cout << "ceci est une forme non défini" << std::endl;
    }

    virtual void GetShapeType() const = 0;

protected :
    float x, y;
};


class Cercle : public Shape
{
public :

    Cercle(float X, float Y, float RADIUS) : Shape(X,Y), rayon(RADIUS){}
    void draw() const override
    {
        std::cout << " x : " << this->x << " y : " << this->y << " rayon : " << this->rayon << std::endl;
    }
    void GetShapeType() const
    {
        std::cout << "je suis un cercle" << std::endl;
    }

protected :
    float rayon;
};


class Carre : public Shape
{
public:

    Carre(float X, float Y, float COTE) : Shape(X, Y), cote(COTE) {}
    void draw() const override
    {
        std::cout << " x : " << this->x << " y : " << this->y << " cote : " << this->cote << std::endl;
    }

    void GetShapeType() const
    {
        std::cout << "je suis un carre" << std::endl;
    }

protected:
    float cote;
};

int main()
{
    Carre carre(1.0f, 2.5f, 3.0f);
    carre.GetShapeType();
    carre.draw();
    std::cout << std::endl;
    Cercle cercle(1.0f, 2.5f, 3.0f);
    cercle.GetShapeType();
    cercle.draw();

}
