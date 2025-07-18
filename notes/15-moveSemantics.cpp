/* 1. Copying data is expensive. So how can we avoid needlessly copying data.
 *
 * 2. Sometimes copy is inefficient, for example:
 *      Photo selfie = takePhoto();
 *  We need construct takePhoto(), copy it to selfie, and then destruct it. And
 *  this procedure is time-wasting. Why not just move the content? That's Move
 *  Semantics. But moving is not always safe. For example, if we move something
 *  we will use later, then there will be something wrong
 *
 * 3. rvalues & lvalues:
 *  - lvalues have a definite address, rvalues do not.
 *  - An lvalue can appear on either side of an =, while an rvalue can appear
 *  only right of an =.
 *  - An lvalue's lifetime is until the end of scope. An rvalue's lifetime is
 *  until the end of line
 *  - An lvalue is persistent. An rvalue is temporary
 *
 * 4. Use & as lvalue reference, && as rvalue reference. So we can overload the
 *  function to handle with them in different ways.
 *  Remember, we can do whatever we want with rvalues, becaues they're
 *  temporary.
 *
 * 5. Forcing Move Semantics: Usually we let the compiler decide between & and
 *  &&, but this is not always the most efficient way. If we know that an lvalue
 *  will never be used again, we can use move semantics: std::move(),
 *  this function turns an lvalue to and rvalue so that we can take its resources
 *  immediately. For example:
 *    std::string name = "Chang";
 *    std::vector<std::string> v;
 *    v.push_back(name);              // after this, name = "Chang"
 *    v.push_back(std::move(name));   // after this, name = ""
 *
 *  But try to avoid explicitly using std::move unless you have good reason!
 *  E.g. performance really matters.
 *
 * 6. Rule of Five: If we defined copy constructor/assignment operator and
 *  destructor, we should also define move constructor/assignment operator.
 */
