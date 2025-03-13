#define PI 3.1415


void sphere(int radius, double *volume,double *surface) {//
//radius wird als pass by  as value und rest als pass by refernce also mit adresssoperator &
*volume = (4.0/3)*PI * radius * radius*radius;//4.0 /3 damit  man eine bruch zahl bekommt
*surface = PI * 4 * radius*radius;
}
