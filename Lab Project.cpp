#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;
enum category {Electronics, Food, others, Fashion };

class Product {
protected:
    string name;
    double price;
    int quantity;
    category producttype;
public:
    Product(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    Product(string n, double p, int q, category c) {
        name = n;
        price = p;
        quantity = q;
        producttype = c;
    }
    category getcategory() const
    {
        return producttype;
    }
    int getquantity()
    {
        return quantity;
    }
    void decreasequantity()
    {
        quantity--;
    }
    void editProductPrice(double p) {
        price = p;
    }

    void editProductQuantity(int q) {
        quantity = q;
    }

    void editProductName(string n) {
        name = n;
    }

    double getPrice() const {
        return price;
    }
    void increasequantity()
    {
        quantity++;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void addProduct() {
        quantity++;
    }

    void removeProduct() {
        quantity--;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Price: " << price << ", Quantity: " << quantity;
    }

    friend ostream& operator<<(ostream& os, const Product& product) {
        product.display();
        return os;
    }

    bool operator == (Product p) {
        return(name == p.getName() && price == p.getPrice() && quantity == p.getQuantity());
    }

    void operator = (Product p) {
        name = p.getName();
        price = p.getPrice();
        quantity = p.getQuantity();
    }
};

void swap(Product &a, Product& b)
{
    Product temp = a;
    a = b;
    b = temp;
}
class userManagement {
private:
    map<string, int> users;

public:
    void addUser(string n, int pass) {
        users.insert({ n, pass });
    }

    void removeUser(string n) {
        users.erase(n);
    }

    bool findUser(string n, int p) {
        auto it = users.find(n);
        if (it != users.end() && users[n] == p) {
            return true;
        }
        else {
            return false;
        }
    }

    void editUser(string oldName, string editedName, int editedValue) {
        users.erase(oldName);
        users.insert({ editedName, editedValue });
    }

    void editUserName(string oldName, string editedName) {
        users.insert({ editedName, users[oldName] });
        users.erase(oldName);
    }

    void editUserPassword(string name, int editedValue) {
        users[name] = editedValue;
    }
};

class ProductManagement {
private:
    vector<Product> products;

public:
    void add(Product p) {
        products.push_back(p);
        p.addProduct();
    }
   string getproduct(int i)
    {
        return(products[i].getName());
    }
   Product returnproduct(int i)
   {
       return products[i];
   }
   int getsize()
   {
       return products.size();
   }
   void decreasequantity(int i)
   {
       //cout << "the first quan is" << products[i].getQuantity();

       products[i].decreasequantity();
       //cout << "the second quan is" << products[i].getQuantity();

   }
   int getquantity(int i)
   {
       return products[i].getquantity();
   }
    void remove(Product p) {

        auto it = find(products.begin(), products.end(), p);

        if (it != products.end()) {
            products.erase(it);
        }
        p.removeProduct();
    }

    void searchByName(string n) {
        for (auto it : products) {
            if (it.getName() == n) {
                it.display();
            }
            else {
                cout << "Product " << n << " is not found!";
            }
        }
    }

    void searchByPrice(int p) {
        for (auto it : products) {
            if (it.getPrice() == p) {
                it.display();
            }
            else {
                cout << "The product of price " << p << " is not found!";
            }
        }
    }

    vector<Product> sort(const string& sort_by) {

        vector<Product> sortedProducts = products;

        if (sort_by == "Price") {
            for (int i = 0; i < products.size() - 1; i++) {
                for (int j = 0; j < products.size() - i - 1; j++) {
                    if (products[j].getPrice() > products[j + 1].getPrice()) {
                        swap(products[j], products[j + 1]);
                    }
                }
            }
        }
        else if (sort_by == "Quantity") {
            for (int i = 0; i < products.size() - 1; i++) {
                for (int j = 0; j < products.size() - i - 1; j++) {
                    if (products[j].getQuantity() > products[j + 1].getQuantity()) {
                        swap(products[j], products[j + 1]);
                    }
                }
            }
        }
        else if (sort_by == "Name") {
            for (int i = 0; i < products.size() - 1; i++) {
                for (int j = 0; j < products.size() - i - 1; j++) {
                    if (products[j].getName() > products[j + 1].getName()) {
                        swap(products[j], products[j + 1]);
                    }
                }
            }
        }
        return sortedProducts;
    }

    void removeByName(string s) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getName() == s) {
                products.erase(products.begin() + i);
                return;
            }
        }
    }

    void editName(string p, string n) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getName() == p) {
                products[i].editProductName(n);
                return;
            }
        }
    }

    void editPrice(string p, double price) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getName() == p) {
                products[i].editProductPrice(price);
                return;
            }
        }
    }

    void editQuantity(string p, int q) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getName() == p) {
                products[i].editProductQuantity(q);
                return;
            }
        }
    }

    bool isProductAvailable(string productName) const {
        for (const auto& product : products) {
            if (product.getName() == productName) {
                return true;
            }
        }
        return false;
    }

    void display() const {
        cout << "Available products are: " << endl;
        for (const auto& product : products) {
            cout << product << endl;
        }
    }

    void operator+(const Product& product) {
        add(product);
    }

    void operator-(const Product& product) {
        remove(product);
    }
    void displaycategory(category c)
    {
        cout << "Available products in this category are: " << endl;
        for (const auto& product : products) 
        {
            if (product.getcategory() == c)
            {
                cout << product << endl;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const ProductManagement& other) {
        os << "Products:" << endl;
        for (const auto& product : other.products) {
            product.display();
            os << endl;
        }
        return os;
    }
};

class ShoppingCart {
private:
    vector<Product> items;
    ProductManagement* currentpm;
    int total;

public:
    ShoppingCart(ProductManagement* pm)
    {
        currentpm = pm;
        total = 0;
    }
    void addItem(string a) {
        int size = currentpm->getsize();
        //cout << "size is: "<<size<<endl;
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (a == currentpm->getproduct(i))
            {

                //cout << "item found" <<i;
                found = true;
                if (currentpm->getquantity(i) > 0)
                {
                    
                    //cout << currentpm.returnproduct(i).getName();
                    items.push_back(currentpm->returnproduct(i));
                    currentpm->decreasequantity(i);

                    //cout << total;
                    //cout << currentpm.returnproduct(i).getPrice();
                    
                    total = total + currentpm->returnproduct(i).getPrice();
                    //cout << "fina l total" << total;
                    cout << "The product " << (currentpm->getproduct(i))<< " is successfully added to your cart." << endl;
                    break;
                }
                else if (currentpm->getquantity(i) == 0)
                    cout << "The product " << (currentpm->getproduct(i)) << " is out of stock." << endl;
            }
        }
        if (!found)
        {
            cout << "Item not found!" << endl;
        }
    }

    void removeItem(string a) {
        //auto it = find(items.begin(), items.end(), product);
        //if (it != items.end()) {
        //    items.erase(it);
        //}
        bool found = false;
        int size = currentpm->getsize();
        for (int i = 0; i < size; i++)
        {
            if (a == items[i].getName())
            {
                items.erase(items.begin() + i);
                found = true;
                (currentpm->returnproduct(i)).increasequantity(); //check that this line of code changes the quantity that appears in the product manager class itself
                total = total - (currentpm->returnproduct(i)).getPrice();
                cout << "The product is removed now from your cart"<<endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Item not found!" << endl;
        }
    }

    bool contains(Product product) {
        return find(items.begin(), items.end(), product) != items.end();
    }

    size_t getItemCount() const {
        return items.size();
    }

    void displayItems() const {
        for (const auto& item : items) {
            cout << item.getName() << endl;
        }
    }

    double calculateTotal() const {
        /*double totalPrice = 0.0;
        for (const auto& item : items) {
            totalPrice += item.getPrice() * item.getQuantity();
        }
        return totalPrice;*/
        return total;
    }
};

int main() {

    ProductManagement* generalManager=new ProductManagement;
    userManagement u;

    Product p1("Iphone 14", 40000, 3, Electronics);
    Product p2("Samsung TV", 25000, 7, Electronics);
    Product p3("Baby Doll", 300, 40,others);
    Product p4("T-Shirt", 150, 32, Fashion);
    Product p5("Pizza", 80, 15,Food);

    generalManager->add(p1);
    generalManager->add(p2);
    generalManager->add(p3);
    generalManager->add(p4);
    generalManager->add(p5);

    char ans;

    do {
        cout << "Welcome to our online shopping system!" << endl;
        cout << "Kindly press m if you are an administrator and press u if you are a user and e if you want to exit " << endl;
        cin >> ans;
        cout << endl;

        if (ans == 'm') {
            string name, password;
            cout << "Kindly enter the log-in credentials of the administration:" << endl << "Enter the username:" << endl;
            cin >> name;
            cout << "Enter the password: " << endl;
            cin >> password;

            if (name == "admin" && password == "password") {
                string action;

                do {
                    cout << "Please type the action you need to do following this guideline: " << endl
                        << "To add a user: adduser " << endl << "To remove a user: removeuser " << endl
                        << "To edit a user's data: edituser" << endl
                        << "To add a product: addproduct " << endl
                        << "To remove a product: removeproduct " << endl
                        << "To edit a product's data: editproduct" << endl
                        << "To display the products : displayproducts" << endl
                        << "To get out of the application: end" << endl;
                    cin >> action;

                    if (action == "adduser") {
                        string n; int p;
                        cout << "Please enter the username and password of the user you want to add respectively: ";
                        cin >> n >> p;
                        u.addUser(n, p);
                    }

                    else if (action == "removeuser") {
                        string n;
                        cout << "Please enter the username of the user you want to remove: ";
                        cin >> n;
                        u.removeUser(n);
                    }

                    else if (action == "edituser") {
                        string answer;
                        cout << "Do you want to edit the user's name or password or both? (type n for name or pass for password or b for both)";
                        cin >> answer;

                        if (answer == "n") {
                            string old, edited;
                            cout << "Please enter the name you need to edit and the edited name respectively: ";
                            cin >> old >> edited;
                            u.editUserName(old, edited);
                        }

                        else if (answer == "pass") {
                            string n; int p;
                            cout << "Please enter the name of the user that you want to edit his password and the new password: ";
                            cin >> n >> p;
                            u.editUserPassword(n, p);
                        }

                        else if (answer == "b") {
                            string old, edited; int p;
                            cout << "Please enter the name of the user that you want to edit his credentials";
                            cin >> old;
                            cout << "Please enter the new credentials, username and password respectively: ";
                            cin >> edited >> p;
                            u.editUser(old, edited, p);
                        }
                    }
                    else if (action == "addproduct") {
                        string pname;
                        double pprice;
                        int pq;
                        category c;
                        cout << "Kindly enter the name, price, and quantity of this new product:" << endl;
                        cin >> pname >> pprice >> pq;
                        char cat;
                        cout << "Kindly set the category of this new product, press e if electronics, f if food, s if fashion, and o if other:" << endl;
                        cin >> cat;
                        if (cat == 'e')
                            c = Electronics;
                        else if (cat == 'f')
                            c = Food;
                        else if (cat == 's')
                            c = Fashion;
                        else
                            c = others;
                        Product newproduct(pname, pprice, pq, c);
                        generalManager->add(newproduct);
                    }

                    else if (action == "removeproduct") {
                        string nametoberemoved;
                        cout << "Kindly enter the name of the product you need to remove: " << endl;
                        cin >> nametoberemoved;
                        generalManager->removeByName(nametoberemoved);
                    }

                    else if (action == "editproduct") {
                        string nametobeedited;
                        cout << "Kindly enter the name of the product you need to edit: " << endl;
                        cin >> nametobeedited;
                        char edit;
                        cout << "Kindly enter the way you want to edit it, if you want to edit its name enter n, if its price press p, if its quantity press q: " << endl;
                        cin >> edit;

                        if (edit == 'n') {
                            string fname;
                            cout << "Kindly enter the new name: " << endl;
                            cin >> fname;
                            generalManager->editName(nametobeedited, fname);
                        }

                        else if (edit == 'p') {
                            double fprice;
                            cout << "Kindly enter the new price: " << endl;
                            cin >> fprice;
                            generalManager->editPrice(nametobeedited, fprice);
                        }

                        else if (edit == 'q') {
                            int fquant;
                            cout << "Kindly enter the new quantity: " << endl;
                            cin >> fquant;
                            generalManager->editQuantity(nametobeedited, fquant);
                        }
                    }

                    else if (action == "displayproducts") {
                        generalManager->display();
                    }

                } while (action != "end");
            }

            else {
                cout << "Error! Username or passowrd is invalid, please try again.";
                return 0;
            }
        }

        else if (ans == 'u') {
            string name; int password;
            cout << "Kindly enter the log-in credentials." << endl << "Enter the username:" << endl;
            cin >> name;
            cout << "Enter the password: " << endl;
            cin >> password;

            if (u.findUser(name, password)) {
                string action;
                ShoppingCart* usercart = new ShoppingCart(generalManager);
                do {
                    cout << "Please type the action you need to do following this guideline: " << endl
                        << "To check whether a product is available or not: check " << endl
                        << "To search a product by name and display it: searchByName " << endl
                        << "To search a product by price and display it: searchByPrice" << endl
                        << "To display available products sorted by name: sortByName " << endl
                        << "To display available products sorted by price: sortByPrice " << endl
                        << "To display available products sorted by quantity: sortByQuantity " << endl
                        << "To add a product to your cart: addproduct " << endl
                        << "To remove a product from your cart: removeproduct " << endl
                        << "To display your products: displayproducts "<<endl
                        << "To proceed to checkout: checkout"<<endl
                        << "To shop by category: category" << endl
                        << "To get out of the application: end" << endl;

                    cin >> action;

                    if (action == "check") {
                        string n;
                        cout << "Please enter the name of the product you want to check: " << endl;
                        cin >> n;
                        if (generalManager->isProductAvailable(n)) {
                            cout << "The product " << n << " is available.";
                        }
                        else {
                            cout << "The product " << n << " isn't available";
                        }
                    }
                    else if (action == "searchByName") {
                        string n;
                        cout << "Please enter the name of the product you want to search: " << endl;
                        cin >> n;
                        generalManager->searchByName(n);
                    }
                    else if (action == "searchByPrice") {
                        int p;
                        cout << "Please enter the price of the item you want to search: " << endl;
                        cin >> p;
                        generalManager->searchByPrice(p);
                    }
                    else if (action == "sortByName") {
                        generalManager->sort("Name");
                        generalManager->display();
                    }
                    else if (action == "sortByPrice") {
                        generalManager->sort("Price");
                        generalManager->display();
                    }
                    else if (action == "sortByQuantity") {
                        generalManager->sort("Quantity");
                        generalManager->display();
                    }
                    else if(action =="addproduct")
                    {
                        string pname;
                        cout << "Kindly enter the name of the product you want to buy: "<<endl;
                        cin >> pname;
                        usercart->addItem(pname);

                    }
                    else if (action == "removeproduct")
                    {
                        string pname;
                        cout << "Kindly enter the name of the product you want to remove: " << endl;
                        cin >> pname;
                        usercart->removeItem(pname);
                    }
                    else if (action == "displayproducts")
                    {
                        cout << "The products in your cart are: " << endl;
                        usercart->displayItems();
                    }
                    else if (action == "category")
                    {
                        char categ;
                        cout << "Kindly enter the category you need: e for electronics, f for food, s for fashion, and o for others" << endl;
                        cin >> categ;
                        if (categ == 'e')
                            generalManager->displaycategory(Electronics);
                        else if (categ == 'f')
                            generalManager->displaycategory(Food);
                        else if (categ == 's')
                            generalManager->displaycategory(Fashion);
                        else
                            generalManager->displaycategory(others);
                    }
                    else if (action == "checkout")
                    {
                        cout << "The total price you need to pay is: " << usercart->calculateTotal();
                        char confirm;
                        cout << "If you want to confirm your order press 'c'" << endl;
                        cin >> confirm;
                        if (confirm == 'c')
                        {
                            string payment;
                            do {
                                cout << "Kindly choose your payment method: creditcard, cash:" << endl;
                                cin >> payment;
                            }
                            while  (payment  !=  "cash" && payment !="creditcard");
                            if (payment == "cash")
                            {
                                cout << "Order placed succesfully! Payment method is cash";
                            }
                            else
                            {
                                int cc;
                                cout << "Kindly enter your credit number" << endl;
                                cin >> cc;
                                cout << "Order placed succesfully! Payment method is via credit card";

                            }
                        }
                        else
                        {
                            cout << "Confirmation failed" << endl;
                        }

                    }
                    else {
                        cout << "Error! Your answer cannot be understood, please try again.";
                    }
                } while (action != "end");
            }

            else {
                string answer;
                cout << "Username or password doesn't exist. Do you need to register your account? (Type y for Yes and n for No)" << endl;
                cin >> answer;
                if (answer == "y" || answer == "Y") {
                    u.addUser(name, password);
                    cout << "Your account is registered successfuly! Please log-in again.";
                }
            }
        }
    } while (ans != 'e');

    return 0;
}
