
#ifndef OPENAV_AVTK_TEST_UI_HXX
#define OPENAV_AVTK_TEST_UI_HXX

#include "avtk/avtk.hxx"

// FIXME: refactor?
static void widgetCB(Avtk::Widget* w, void* ud)
{
  //printf( "widgetCB(), label = %s\n", w->label.c_str() );
  
  /*
  std::vector< std::string > files;
  
  Avtk::directoryContents( "/root", files );
  
  for( int i = 0; i < files.size(); i++)
    printf("%i : %s\n", i, files.at(i).c_str() );
  */
}

class TestUI : public Avtk::UI
{
  public:
    TestUI():
      Avtk::UI( 610, 430 )
    {
      addRow( 0, 72 );
      
      for(int i = 0; i < 16; i++)
        addRow( 72 + i * ( 3 + 22 ) );
    }
    
    void addRow( int offset, int btnW = 22 )
    {
      for(int r = 0; r < 10; r++ )
      {
        Avtk::Widget* w = 0;
        int spcr =  3;
        int btnH = 22;
        w = new Avtk::Button( offset + spcr + btnH, 10 + ( btnW + spcr )* r, btnW, btnH, "-" );
        w->callback = widgetCB;
        w->callbackUD = this;
        add( w );
      }
      
    }
};

#endif // OPENAV_AVTK_TEST_UI_HXX
