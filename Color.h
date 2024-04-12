enum class Color
{
    Red,
    Blue
};

inline std::string colorToString(Color color) 
{
    switch(color) 
    {
        case Color::Red:
            return "Red";
        case Color::Blue:
            return "Blue";
        default:
            return "Unknown";
    }
};


inline std::ostream& operator<<(std::ostream& stream, const Color& color) 
{
    stream << colorToString(color);
    return stream;
};
