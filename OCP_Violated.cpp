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
// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToSQLDatabase() {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }

    void saveToMongoDatabase() {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }

    void saveToFile() {
        cout << "Saving shopping cart to File..." << endl;
    }
};



int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();

    return 0;
}