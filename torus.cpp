#include<iostream>
#include<math.h>
#include<conio.h>
#include<windows.h>


const int screen_height = 40,screen_width = 2*screen_height;
const int center_height = screen_height/2, center_width = screen_width/2;
float screen[screen_height][screen_width][screen_height] = {{{0}}};
float r,R;
float pi = 3.1415;

std :: string lighting(int i,int j,int k)
{
    float scalar_product = screen[i][j][k];
    scalar_product *= -1;
    scalar_product += 0.48*R;
    scalar_product /= (1.7*R);
    scalar_product *= 12;
    int index = scalar_product;
    std :: string brightness[12] = {".",",","-","~",":",";","=","!","*","#","$","@"};
    if(index > 12) index = 12; if(index < 1) index = 1;
    return brightness[index - 1];
}
void print()
{
    for(int i = 0; i < screen_height; i++)
    {
        for(int j = 0; j < screen_width; j++)
        {
            int temp = 0;
            for(int k = 0; k < screen_height; k++)
            {
                if(screen[i][j][k] != 0)
                {
                    temp = k;
                }
            }
            if(temp != 0) std :: cout << lighting(i,j,temp);
            else std :: cout << " ";
        }
        std :: cout << "\n";
    }
}
void torus(float phi,float theta)
{
    float x,xx,x1,y,yy,y1,z,zz,z1;
    float scalar_product;
    int X1,Y1,Z1;
    for(float X = 0; X < 2*pi; X += pi/180)
    {
        for(float O = 0; O < 2*pi; O += pi/180)
        {
            x = ((R + r*cos(O))*cos(X));
            y = (r*sin(O))*cos(phi) - (-(R + r*cos(O))*sin(X))*sin(phi);
            z = (r*sin(O))*sin(phi) + (-(R + r*cos(O))*sin(X))*cos(phi);

            xx = 2*(x*cos(theta) + z*sin(theta));
            yy = y;
            zz = -x*sin(theta) + z*cos(theta);
            
            x = R*cos(X);
            y = (R*sin(X))*sin(phi);
            z = -(R*sin(X))*cos(phi);

            x1 = 2*(x*cos(theta) + z*sin(theta));
            y1 = y;
            z1 = -x*sin(theta) + z*cos(theta);

            scalar_product = (xx - x1) + (yy - y1) - 2*(zz - z1);

            Y1 = yy + center_height;
            X1 = xx + center_width;
            Z1 = zz + center_height;

            screen[Y1][X1][Z1] = scalar_product;
        }
    }
}
void clear_screen()
{
    for(int i = 0; i < screen_height; i++)
    {
        for(int j = 0; j < screen_width; j++)
        {
            for(int k = 0; k < screen_height; k++)
            {
                screen[i][j][k] = 0;
            }
        }
    }
}

int main()
{
    R = 12; r = 6;

    while(!kbhit())
    {
        Sleep(200);
    }
    for(float theta = 0; theta <= 4*pi; theta += pi/60)
    {
        clear_screen();
        torus(theta*0.5,theta);
        std :: cout << std :: flush;
        std :: cout << system("CLS");
        print();
    }
}