
#include "Domain.h"

void Lifted::PDDLPrint( std::ostream & s, unsigned indent, const TokenStruct< std::string > & ts, Domain & d ) {
	tabindent( s, indent );
	s << "( " << name;
	for ( unsigned i = 0; i < params.size(); ++i ) {
		if ( ts.size() ) s << ts[i];
		else s << " ?" << d.types[params[i]]->getName() << i;
		if ( d.typed ) s << " - " << d.types[params[i]]->name;
	}
	s << " )";
}

void Lifted::parse( Filereader & f, TokenStruct< std::string > & ts, Domain & d ) {
	TokenStruct< std::string > lstruct = f.parseTypedList( true, d.types );
	params = d.convertTypes( lstruct.types );
}

void Lifted::SHOPparse( Filereader & f, TokenStruct< std::string > & ts, Domain & d ) {
	TokenStruct< std::string > lstruct = f.parseTypedList( false );
	params = d.convertTypes( lstruct.types );
}
