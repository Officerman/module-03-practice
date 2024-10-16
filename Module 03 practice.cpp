#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class User {
public:
    User(const std::string& n, const std::string& e, const std::string& r)
        : name(n), email(e), role(r) {}

    void update(const std::string& n, const std::string& e, const std::string& r) {
        name = n;
        email = e;
        role = r;
    }

    void display() const {
        std::cout << "Name: " << name << ", Email: " << email << ", Role: " << role << std::endl;
    }

    std::string getEmail() const {
        return email;
    }

private:
    std::string name;
    std::string email;
    std::string role;
};

class UserManager {
public:
    void addUser(const User& user) {
        users.push_back(user);
    }

    void removeUser(const std::string& email) {
        auto it = findUser(email);
        if (it != users.end()) {
            users.erase(it);
        } else {
            std::cout << "User not found." << std::endl;
        }
    }

    void updateUser(const std::string& email, const std::string& name, const std::string& newEmail, const std::string& role) {
        auto it = findUser(email);
        if (it != users.end()) {
            it->update(name, newEmail, role);
        } else {
            std::cout << "User not found." << std::endl;
        }
    }

    void displayUsers() const {
        for (const auto& user : users) {
            user.display();
        }
    }

private:
    std::vector<User> users;

    std::vector<User>::iterator findUser(const std::string& email) {
        return std::find_if(users.begin(), users.end(), [&email](const User& u) {
            return u.getEmail() == email;
        });
    }
};

int main() {
    UserManager um;

    um.addUser(User("Alice", "alice@example.com", "Admin"));
    um.addUser(User("Bob", "bob@example.com", "User"));

    std::cout << "Users after addition:" << std::endl;
    um.displayUsers();

    um.updateUser("bob@example.com", "Robert", "robert@example.com", "Admin");

    std::cout << "\nUsers after update:" << std::endl;
    um.displayUsers();

    um.removeUser("alice@example.com");

    std::cout << "\nUsers after removal:" << std::endl;
    um.displayUsers();

    return 0;
}
