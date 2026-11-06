#include<iostream>
#include<vector>
 using namespace std;


// Product class representing any item of any Ecommerce
class Product{
       public:
       string name;
       double price;


       Product(string name,double price){
        this->name=name;
        this->price=price;
       }
};

//Violating SRP: Shopping Cart is handling multiple responsibilities
class ShoppingCart{
    private:
    vector<Product*> products;
    public:
    void addProduct(Product *p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }

    // 1. Calculate total Price in the Cart
    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }return total;
    }
    //   2. Violating SRP- Prints invoice (Should be in a separate class)
    void printInvoice(){
        cout<<"Shopping Cart Invoice:\n";
        for(auto p : products){
            cout<<p->name<<" "<<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }
    // 3. Violating SRP- Saves to DB( should be in separate class)
    void saveToDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
    }
};


int main(){
    ShoppingCart* cart= new ShoppingCart();

    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",500));

    cart->printInvoice();
    cart->saveToDatabase();
    return 0;
}

