#include<iostream>
#include<vector>
using  namespace std;

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

// Following SRP: ShoppingCart is handling only one responsibility
class ShoppingCart{
    private:
    vector<Product*>products;
    public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>&getProducts(){
        return products;
    }

    //Calculate total profit in price
     double calculateProfit(){
        double total=0;
        for(auto p: products){
            total+=p->price;
        }
        return total;
     }     
};


// 2. ShoppingCartPrinter only responisble for invoice handling
 class ShoppingCartPrinter{
    private:
    ShoppingCart* cart;
    public:
    ShoppingCartPrinter(ShoppingCart* s){
        this->cart=s;
    }
    void printInvoice(){
     cout<<"Shopping Cart Invoice:\n";
        for(auto p : cart->getProducts()){
            cout<<p->name<<" "<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateProfit()<<endl;        
    }
 };


 // 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();

    return 0;
}