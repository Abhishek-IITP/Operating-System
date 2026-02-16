struct obj{
  const char *name;
  int age;
};

int main(){
  const auto mohit = new obj{name : "Mohit" , age : 22};
  mohit-> name = "Abhijeet kumar";
  mohit->age = 20;
}
