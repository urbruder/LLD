#include<iostream>
#include<vector>

using namespace std;
 class Product{
    public:
    string name;
    double price;
    Product(string name, double price){
       this->name=name;
       this->price=price;
    } 
 };

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
    // CALCULATES TOTAL PRICE IN CART
    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    } 
 };

 class ShoppingCartPrinter{
    private:
     ShoppingCart* cart;
    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"Shopping cart invoice:\n";
        for(auto p:cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};

class Persistence{
    private:
    ShoppingCart* cart;
    public:
    virtual void save(ShoppingCart* cart)=0;
};

class SQLPersistence: public Persistence{
       public:
        void save(ShoppingCart* cart) override{
            cout<<"Saving shopping cart to SQL DB..."<<endl;
        }
};
class MongoPersistence: public Persistence{
       public:
        void save(ShoppingCart* cart) override{
            cout<<"Saving shopping cart to MongoDB..."<<endl;
        }
};
class FilePersistence: public Persistence{
       public:
        void save(ShoppingCart* cart) override{
            cout<<"Saving shopping cart to File..."<<endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart);   // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File

    return 0;
}