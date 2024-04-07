enum class Color
{
    Red,
    Blue
};

std::string colorToString(Color color) {
    switch(color) {
        case Color::Red:
            return "Red";
        case Color::Blue:
            return "Blue";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& stream, const Color& color) {
    // Implement logic to print the Color object to the stream
    stream << colorToString(color); // Assuming Color is an enum class
    return stream;
}