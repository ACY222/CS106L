#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
#include <cctype>
#include <string>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

// using traditional STL algorithms
//
// See them in spellcheck.h
// struct Token { std::string content; size_t src_offset; };
// using Corpus = std::set<Token>
Corpus tokenize(std::string& source) {
    /* TODO: Implement this method */
    // Step One: Identify all iterators to space characters
    /* auto iterVec = find_all(source.begin(), source.end(), std::isspace); */
    auto iterVec = find_all(source.begin(), source.end(), [](char c)
            { return std::isspace(static_cast<int>(c)); });
    // Step Two: Generate tokens between consecutive space characters
    auto tokenSet = Corpus(); // default constructor
    // transform(first1, last1, first2, d_first, binary_op):
    // Given two equally-sized ranges, defined by first1, first2, last1, applies
    // a binary function binary_op to each pair of iterators from the two
    // ranges and stores the result to the output range starting at d_first
    //
    // inserter(c, i):
    // An output iterator that inserts any value written to it into the
    // container c at position i, which can be passed as the output range to
    // other STL algorithms
    //
    // Thus, tokenSet[0] = Token(source, iterVec[0], iterVec[1]);
    //      tokenSet[1] = Token(source, iterVec[1], iterVec[2]);
    //      and so on.
    std::transform(iterVec.begin(), iterVec.end() - 1, iterVec.begin() + 1, 
            std::inserter(tokenSet, tokenSet.end()),
            [&source](auto it1, auto it2) { return Token(source, it1, it2); });
    // Step Three: Get rid of empty tokens
    std::erase_if(tokenSet, [](const Token& token){ return token.content.empty(); });
    return tokenSet;
}

// using the brand new ranges library
// struct Misspelling { Token token; set<string> suggestions; }
std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    /* TODO: Implement this method */
    // source is the output of my tokenize method
    namespace rv = std::ranges::views;

    auto notInDictionary = [&dictionary](const Token& token) 
        { return !dictionary.contains(token.content); };

    auto findMisspelings = [&dictionary](const Token& token){
            // if the distance between token and word in dict is one
            auto distIsOne = [&token](const std::string& wordInDict)
                { return levenshtein(token.content, wordInDict) == 1; };
            auto suggestionsView = rv::filter(dictionary, distIsOne);
            std::set<std::string> suggestions(suggestionsView.begin(), 
                    suggestionsView.end());
            return Misspelling {token, suggestions};
        };

    auto hasSuggestions = [](const Misspelling& m) {
        return !m.suggestions.empty();
    };

    auto misspellingsView = source 
    // Step One: Skip words that are already correctly spelled(in dictionary)
        | rv::filter(notInDictionary)           // we get misspelled words
    // Step Two: Find one-edit-away words in the dictionary using Damerau-Levenshtein
        | rv::transform(findMisspelings)        // we get misspellings
    // Step Three: Drop misspellings with no suggestions.
        | rv::filter(hasSuggestions);         // we filter empty suggestions
    std::set<Misspelling> result(misspellingsView.begin(), misspellingsView.end());
    return result;
}

/* Helper methods */

#include "utils.cpp"
