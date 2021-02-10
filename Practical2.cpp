#include <iostream>
#include <cmath>
using namespace std;


void ex1(double x, double y, double cx, double cy, double r){
  cout<<"Please enter the x coordinate of the point: ";
  cin>>x;

  cout<<"Please enter the y coordinate of the point: ";
  cin>>y;

  cout<<"Please enter the x coordinate of the center: ";
  cin>>cx;

  cout<<"Please enter the y coordinate of the center: ";
  cin>>cy;

  cout<<"Please enter the radius of the circle: ";
  cin>>r;

  int q = (x-cx)*(x-cx) + (y-cy)*(y-cy);
  if (q<=r*r){
    cout<<"The point ("<<x<<";"<<y<<") is enclosed in the circle of center ("<<cx<<";"<<cy<<") and of radius "<<r;
  }
  else{
    cout<<"The point ("<<x<<";"<<y<<") is not enclosed in the circle of center ("<<cx<<";"<<cy<<") and of radius "<<r;
  }

}


void ex2(double p, double s, double a, int n, double dt){
  cout<<"Please enter the initial position: ";
  cin>>p;

  cout<<"Please enter the initial speed: ";
  cin>>s;

  cout<<"Please enter the acceleration: ";
  cin>>a;

  cout<<"Please enter the number of position to compute: ";
  cin>>n;

  cout<<"Please enter the time between each positions: ";
  cin>>dt;

  cout<<"Acceleration: "<<a<<" Initial speed: "<<s<<" Initial position: "<<p<<" Number of times: "<<n<<" Delta t: "<<dt<<endl;

  cout<<"At time 0 the position is: "<<p<<endl;
  for (int i = 1; i<=n;i++){
    double newp;
    double t = i*dt;
    newp = p + s*t + (1/(2*a))*t*t;
    p = newp;
    cout<<"At time "<<t<<" the position is: "<<newp<<endl;
   }
}

void ex3 (int& x, int& y){
  int temp = x;
  x = y;
  y = temp;
}

void ex4(int n){
  cout<<"Please enter the number of rows that you want: ";
  cin>>n;

  int number = 1;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; ++j){
      cout << number << " ";
      number++;
    }

    cout << endl;
    }

}

void ex5(int n){
  int fn1, fn2;
  fn1 = 0;
  fn2 = 1;

  cout<<"Please enter the fibonacci number that you want to compute: ";
  cin>>n;

  if(n==0){
    cout<<fn1<<endl;
  }
  else if (n==1){
    cout<<fn2<<endl;
  }
  else{
    for (int i = 1; i<=n;i++){
      int temp = fn1;
      fn1 = fn1 + fn2;
      fn2 = temp;
    }
    cout<<fn1<<endl;
  }

}

int ex6(int n){

  if((n==1)||(n==0)) {
    return(n);
  }
  else {
      return(ex6(n-1)+ ex6(n-2));
   }
}

int ex7a(int a, int n){
  if(n==0){
    return 1;
  }
  else{
    return(a*ex7a(a,(n-1)));
  }
}

int ex7b(int a, int n){
  if(n==0){
    return 1;
  }
  else if(n%2==0){
    return(ex7b(a,(n/2))*ex7b(a,(n/2)));
  }
  else{
    return(ex7b(a,(n/2))*ex7b(a,(n/2))*a);
  }
}


int main(){
  double x,y,cx,cy,r;
  ex1(x,y,cx,cy,r);

  double p,s,a,n,dt;
  ex2(p,s,a,n,dt);

  int x,y;
  x = 4;
  y = 10;
  ex3(x,y);
  cout<<x<<endl;
  //cout<<y<<endl;

  int n;
  ex4(n);

  int n2;
  ex5(n2);

  int n3;
  cout<<"Please enter the fibonacci number that you want to compute: ";
  cin>>n3;
  cout<<ex6(n3);

  int a,n4;
  a = 3;
  n4 = 3;
  cout<<ex7a(a,n4);

  int a2,n5;
  a2 = 3;
  n5 = 3;
  cout<<ex7b(a2,n5);
}