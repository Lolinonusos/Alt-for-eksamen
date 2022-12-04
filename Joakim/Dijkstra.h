#pragma once

// Dette blir tekst basert p� video p� norsk

/*
Dijkstra1: https://www.youtube.com/watch?v=u9Sum4d1QUE&ab_channel=DagNylund
	
	Dynamisk representasjon av grafen v�r
		Dvs:
		En klasse for node
		En klasse for kant
		Muligens en klasse for graf			En graf best�r av noder og kanter.
		Muligens retning p� kantene, som pil fra A til B, som betyr at du kan g� fra A til B.
		Mulig � ha en graf som kan g� begge veier. Urettet graf, kan da g� fra A til B og B til A. Da er kantene AB og BA med som de forskjellige kantene.
		Geomoetri <> Topologi. Avstand mellom nodene trenger ikke ha en sammenheng med nodenes plassering. 




		// Random ass YouTube comment from this vid: https://www.youtube.com/watch?v=SnZ2SQARTVI&ab_channel=ApnaCollege

        The set doesn't actually have to be a pair. You can make it a set of integers itself where the integers will be the nodes.
        Also simply insert a node only if the if-block for distance is satisfied. No need for erasing inside the if-block then.

        This code worked fine for me:
	        s.insert(src);
            dist[src]=0;

            while (!s.empty())
            {
                    x=*s.begin();
                    s.erase(x);

                for(auto it:graph[x])
                {
                        if(dist[it.first]>(dist[x]+it.second))
                    {
                        dist[it.first]=dist[x]+it.second;
                        s.insert(it.first);
                    }
                }
            }





*/
