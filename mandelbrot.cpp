#include <complex>
#include <iostream>
int main() {
    const size_t limit = 1000, size = 400; // change 'size' to make it more detailed
    const char letters[] = " 123456789abcdefghijklmnopqrstuvwxyz*";
    for (size_t iy = 0; iy <= size; iy++) {
        for (size_t ix = 0, count = 0; ix <= size; ix++, count = 0) {
            std::complex<double> c(-2.0+ix*2.5/size, 1.15-iy*2.3/size), z(0.0, 0.0);
            while (std::norm(z) < 4.0 && count++ < limit) z = z*z+c;
            std::cout << ((count >= limit) ? letters[0] : letters[std::min(count, sizeof(letters)-2)]);
        }
        std::cout <<std::endl;
    }
    return 0;
}