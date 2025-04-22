#include <iostream>
#include <cmath>

class Cercle {
private:
    double rayon;
    double x, y; // Coordonnées du centre

public:
    Cercle(double r, double cx, double cy) : rayon(r), x(cx), y(cy) {}

    double get_rayon() const { return rayon; }
    void set_rayon(double r) { rayon = r; }

    double get_x() const { return x; }
    double get_y() const { return y; }
    void translate(double dx, double dy) { x += dx; y += dy; }

    double surface() const { return M_PI * rayon * rayon; }
    double perimetre() const { return 2 * M_PI * rayon; }

    bool est_egal(const Cercle& autre) const {
        return rayon == autre.rayon && x == autre.x && y == autre.y;
    }

    bool appartient(double px, double py) const {
        return std::sqrt(static_cast<double>((px - x) * (px - x) + (py - y) * (py - y))) <= rayon;
    }

    void affiche() const {
        std::cout << "Cercle de rayon " << rayon << " centré en (" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Cercle c1(1.0, 10.0, 10.0);
    c1.affiche(); // Affiche : Cercle de rayon 1 centré en (10, 10)

    std::cout << "Périmètre : " << c1.perimetre() << std::endl;
    std::cout << "Surface : " << c1.surface() << std::endl;

    c1.set_rayon(2.0);
    std::cout << "Périmètre après changement de rayon : " << c1.perimetre() << std::endl;
    std::cout << "Surface après changement de rayon : " << c1.surface() << std::endl;

    c1.translate(-10.0, -10.0);
    c1.affiche(); // Affiche : Cercle de rayon 2 centré en (0, 0)

    std::cout << "Le point (1, 1) appartient-il au cercle ? " << (c1.appartient(1.0, 1.0) ? "Oui" : "Non") << std::endl;
    std::cout << "Le point (3, 3) appartient-il au cercle ? " << (c1.appartient(3.0, 3.0) ? "Oui" : "Non") << std::endl;

    Cercle c2(2.0, 0.0, 0.0);
    std::cout << "Les cercles c1 et c2 sont-ils égaux ? " << (c1.est_egal(c2) ? "Oui" : "Non") << std::endl;

    return 0;
}
