# Notes
## Bits of Knowledge
### std::thread & std::bind
Both the operation of the std::thread constructor and the operation of std::bind are defined in terms of the same mechanism. The std::thread constructor takes a function object and arguments and creates a new thread that runs that function object with the given arguments. std::bind takes a function object and arguments and returns a new function object that, when called, runs the original function object with the given arguments. The std::thread constructor is essentially a wrapper around std::bind that creates a new thread to run the function object that std::bind returns.
