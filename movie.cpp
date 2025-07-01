#include <string>
class Movie {
private:
    std::string title;
    std::string duration;
    std::string rating;
    std::string startTime;
public:
    Movie(std::string title, std::string duration, std::string rating, std::string startTime);

//getters
    std::string getTitle() const {
        return this->title;
    };
    std::string getDuration() const {
        return this->duration;
    };
    std::string getRating() const {
        return this->rating;
    };

    std::string getStartTime() const {
        return this->startTime;
    };

//setters
    std::string setTitle(std::string title){
        return this->title = title;
    };
    std::string setDuration(std::string duration){
        return this->duration = duration;
    };
    std::string setRating(std::string rating){
        return this->rating = rating;
    };

    std::string setStartTime(std::string startTime){
        return this->startTime = startTime;
    };

};