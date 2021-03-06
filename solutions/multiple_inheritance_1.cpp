/*
	struct Base { ... }; 

	struct D1 : Base { ... };

	struct D2 : Base { ... }; 

	struct D3 : D1, D2 { ... };
*/

// base указывает на экземпляр Base, соответствующий D1
// нужно вернуть указатель на экземпляр Base, соответствующий D2
Base const * D1BaseToD2Base( Base const * base )
{
    const D1* d1 = (D1*) base;
    const D3* d3 = (D3*) d1;
    const D2* d2 = d3;
    return d2;
}