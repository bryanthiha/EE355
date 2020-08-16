void Network::friends_recommendation(int k){
    // Create vector to hold visited people
    vector<Person*> visited;

    // Create a for BFS
    vector<Person*> recommended;

    // Create a queue that holds who we visit next
    list<Person*> queue;

    // Create pointer that starts at the head of the database 
    Person* ptr = head;

    // Create pointer to traverse database with while doing BFS
    Person* temp;

    // create flag for checking if a friend is already in a vector
    char flag = false;

     // 'i' will be used to get all friends of current person 
    // vertices of a vertex 
    vector<Person*>::iterator i;
    vector<Person*>::iterator v;

    level = 1;
    ctr = 0;
    counter = 0;

    for(int j=0; j<count; j++)
    { // for each person in the database
        cout << "For " << ptr->l_name << ", " << ptr->f_name << ": \n";

        visited.push_back(ptr); // mark the person we are recommending friends to as visited

        

        for(i=ptr->friends.begin(); i!=ptr->friends.end(); ++i){
            // mark the friends of the person we are recommending friends to as visited
            visited.push_back(i);

            // add the friends of the person we are recommending friends to to the queue
            queue.push_back(i);

            ctr++;
        }

        while(!queue.empty()){ // while there are still people to visit
            /* TODO: use k to understand whether or not to add another person to the queue */

            temp = queue.front(); // get next person in the queue
            queue.pop_front(); // dequeue person since we are now looking at them


                /* iterate through the friends of the current person in the queue */
                for(i=temp->friends.begin(); i!=temp->friends.end(); ++i){
                    /* iterate through the visited vector */ 
                    for(v=visited.begin(); v!=visited.end(); ++v){
                        /* check if friend is in the visited vector */
                        if(*i == *v){
                            flag = true;
                            break;
                        }                        
                    }

                    if(flag){ // if friend is in visited
                        flag = false; // reset flag for next friend
                        continue; // go to next friend
                    } else{ // if friend not visited
                        
                        if(level < k-1)
                        {
                            queue.push_back(i);
                            //counter++;
                        }
                        visited.push_back(i); // mark friend as visited
                        recommended.push_back(i); // recommend friend
                    }
                }
        
			
        }

        ptr = ptr->next;
    }

}