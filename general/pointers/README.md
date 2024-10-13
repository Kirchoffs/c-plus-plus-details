# Notes
### Converting unique_ptr to shared_ptr
```
#include <memory>

struct MyClass {
    // Your class definition
};

int main() {
    std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>();
    
    // Convert unique_ptr to shared_ptr by moving
    std::shared_ptr<MyClass> sharedPtr = std::shared_ptr<MyClass>(std::move(uniquePtr));  
}
```

#### Why do we move?
A unique_ptr uniquely owns the object it points to. This means that only one unique_ptr can manage the lifetime of that object at any given time. unique_ptr cannot be copied. __It can only be moved, which transfers ownership from one unique_ptr to another.__
