#ifndef SearchableItemInterface_L
#define SearchableItemInterface_L

//no need to include wx things in this header, just increases compile time
class wxString; 

class SearchableItemInterface 
{
private:
	//currently stored search filter
	wxString current_search_key;
protected:
	//return current search filter
	wxString get_search_key() { return current_search_key; }
public:
	//set key for searching
	virtual void set_search_key(wxString key) { current_search_key=key; }
};

#endif
