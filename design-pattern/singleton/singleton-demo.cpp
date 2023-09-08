class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    
private:
    Singleton() = default;
    Singleton(const Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;
};