#include "connectdb.h"
#include <QtSql>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlError>
ConnectDb::ConnectDb()
{

}
bool ConnectDb::checkConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QODBC" );

      db.setHostName( "localhost" );
      db.setDatabaseName( "Driver={MySQL ODBC 8.0 Unicode Driver};DATABASE=qlsach;"  );

      db.setUserName( "root" );
      db.setPassword( "" );
      if(db.open())
          return true;
      return false;
}
