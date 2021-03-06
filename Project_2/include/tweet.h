#ifndef TWEET_H
#define TWEET_H
#include <iostream>
#include <string>
#include "datetime.h"
#include "user.h"
#include <vector>

/* Forward declaration */
class User;


/**
 * Models a tweet and provide comparison and output operators
 */
class Tweet
{
 public:
  /**
   * Default constructor 
   */
  Tweet();

 

  /**
   * Constructor 
   */
  Tweet(User* user, DateTime& time, std::string& text);

  

  /**
   * Gets the timestamp of this tweet
   *
   * @return timestamp of the tweet
   */
  DateTime const & time() const;

  

  /**
   * Gets the actual text of this tweet
   *
   * @return text of the tweet
   */
  std::string const & text() const;


  /**
   * Return true if this Tweet's timestamp is less-than other's
   *
   * @return result of less-than comparison of tweet's timestamp
   */
  bool operator<(const Tweet& other);




  /**
   * Return true if this Tweet's timestamp is greater-than other's
   *
   * @return result of greater-than comparison of tweet's timestamp
   */
  bool operator>(const Tweet& other);



  /**
   * Outputs the tweet to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS username tweet_text
   *
   * @return the ostream passed in as an argument
   */
  friend std::ostream& operator<<(std::ostream& os, const Tweet& t);



  /**
   * return the replied user's name
   */
  std::vector<std::string> whoIsReplied();



  /**
   * return the vector of all mentioned user's name
   */
  std::vector<std::string> whoIsMentioned();



  /**
   * return true if a tweet starts with @
   */
  bool firstStringCheck();


 private:
  // tweet's poster
  User* _user;

  // tweet's timestamp
  DateTime _time;

  // tweet's pure text
  std::string _text;

};


/* Leave this alone */
struct TweetComp
{
  bool operator()(Tweet* t1, Tweet* t2)
  {
    return (*t1 > *t2);
  }
};

#endif
