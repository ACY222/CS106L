/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>

// Jackie Chan works, Bruce Li also works, but Ai Chang failed.
// Oh, Ai Chang works this time! Though I changed nothing.
std::string kYourName = "Ai Chang"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
    // STUDENT TODO: Implement this function.
    // I don't want to change the relevant function definitions, so I choose set
    std::ifstream fileContent(filename);
    std::set<std::string> students;
    std::string name;
    while (getline(fileContent, name)) {
        students.insert(name);
    }
    std::cout << *students.begin() << '\n';  
    return students;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name. Match means having same first letter in
 * both first name and last name
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
    // STUDENT TODO: Implement this function.
    std::queue<const std::string*> matchs;
    std::stringstream ss(name);
    std::string myFirst, myLast;
    getline(ss, myFirst, ' ');
    getline(ss, myLast, ' ');
    for (auto it = students.begin(); it != students.end(); ++it) {
        std::string matchFirst, matchLast;
        std::stringstream ss(*it);
        getline(ss, matchFirst, ' ');
        getline(ss, matchLast, ' ');
        if (matchFirst[0] == myFirst[0] && matchLast[0] == myLast[0]) {
            matchs.push(&(*it));
        }
    }
    return matchs;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
    // STUDENT TODO: Implement this function.
    if (matches.empty()) {
        std::cout << "NO MATCHES FOUND\n";
        return "NO MATCHES FOUND";
    } 
    return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
