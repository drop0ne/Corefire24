class MyConsoleAPI {
private:
    HANDLE console_HWND; // Handle to the console window

public:
    MyConsoleAPI(); // Constructor
    virtual void clearScreen(); // Clear the console screen
    virtual void cout(const std::string& data); // Print text to the console
    virtual void cout(const std::string& data, int set_tx_color); // Print text to the console
    virtual void setScreenColor(const char* data); // Set the full screen color
    virtual void set_text_color(int data); // Set the text color in the console
};