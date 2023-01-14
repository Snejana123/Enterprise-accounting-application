# Enterprise-accounting-application
Enterprise accounting window application. Qt/C++, Qt version 6.2.3

1.1. Description of the subject area
Accounting consists of many cash registers. Customers come to the accounting department, choosing a cash register. After the service, the customers leave.

2. Diagrams of the object model
2.1. Use Case Diagram

2.2. Entity-relationship model

2.3. Class diagram

2.4 List of library constructor classes used in the project to build the class diagram
QWidget - a class for implementing program user interface widgets
QHBoxLayout - layout for horizontal layout of widgets

2.5. Signal-slot connection scheme implemented in the project

3. Application "Interface"
The application has an MDI interface.

3.1. Graphical representation of interface windows

3.1.1. Main window

Picture 5. Main application window with green theme selected

Picture 6. Main application window with orange theme selected

3.1.2. Software parameters window

Picture 7. Application settings window

3.1.3. Event control window
Picture 8. Application event management window

3.1.4. Object state display window
Picture 9. Window for displaying the state of objects

3.1.5. Interface class header files
MainWindow class - the main window of the application
Attributes:
• -mdiArea: QMdiArea *
• -cashSubW: cashDesksWindow *
• -controlSubW: controlWindow *
• -setSubW: settingsWindow *
• -statBar: QStatusBar *

Methods:
• +MainWindow() – class constructor
• +MainWindow() – class destructor

• -createActions():void – create application menu
• -createStatusBar():void – create application status bar

Slots:
• +backgroundTheme
• +lemonGateSlot
• +fruitBlendSlot
• +plumPlateSlot
• +perfectWhiteSlot
• +equalModeSlot
• +queueLengthModeSlot
• -aboutSlot
• -settingsSlot
• -cashDesksSlot
• -controlWindSlot


class settingsWindow - Domain settings window
Attributes:
• +setWid: settingsWidget * - settings window
• +subWin: QMdiSubWindow* – attribute for placing a window on top of the main one.

Methods:
• +settingsWindow(QWidget *parent) – class constructor
• +~settingsWindow() – class destructor


class controlWindow - Window for managing domain events
Attributes:
• +mainW: controlWidget * - control window
• +subWin: QMdiSubWindow* – attribute for placing a window on top of the main one.

Methods:
• +controlWindow(QWidget *) – class constructor
• +~controlWindow() – class destructor


Class cashDesksWindow - Window for displaying the state of objects
Attributes:
• +mainW: cashWidget * - display window
• -subWin: QMdiSubWindow* – attribute for placing a window on top of the main one.

Methods:
• +cashDesksWindow(QWidget *) – class constructor
• +~cashDesksWindow() – class destructor

4. Application "Model"
4.1. List of events that change the state of the ObD model
Events that change the state of the model:

Accounting:
States: number of cash registers in accounting - N(x)
Developments:
1) Checkout adding K+ 
2) Checkout removing K-
Checkout:
States: Checkout open - From, Checkout closed - Zk, Number of customers in the queue - N(x)
1) Checkout closing ChC
2) Checkout opening ChO
3) Client adding Cl+
4) Client removing ClR-

4.2. State Diagrams of ObD Model Classes

4.3. Header Files of ObD Model Classes

The class cashDeskHBox is a class for implementing checkouts and a queue
Attributes:
• +maxClient: int – maximum client number
• +desksNum: int – checkout number
• +parent: QWidget * - widget for displaying checkouts
• +deskNumber:int – checkout number
• +clients: QVector<QLabel *> - vector of checkout clients
• +isOpen:bool – flag indicating whether the checkout is open
• +deskLabel: QLabel* - label for displaying the checkout
• +mainFont: QFont – font for checkout numbering
• +clientsLabels: QVector<QLabel *> - labels for displaying clients

• +cashDeskHBox(QWidget * , int) – class constructor
• +~cashDeskHBox() – class destructor
• +addClient(int):void – adding a client to the queue
• +deleteClient(int):bool – client leaving
• +isClient(int):bool - check if the client is in the queue
• +closeDesk():void – checkout closing 
• +openDesk():void – checkout opening
• +getDeskNumber():int – checkout number getting
• +getOpenStatus():bool – check if checkout is open or not
• +getMaxClient():int – maximum client number getting 


The cashWidget class is a class for implementing accounting
Attributes:
• deskBoxes: QVector<cashDeskHBox> - vector of checkouts accounting 
• desksBoxes:QVector<cashDeskHBox *> - vector of accounts department checkout addresses
• cashL: QVBoxLayout* - layout for vertical display of checkouts
• parent: QWidget * - parent widget to display
• probMode: int – queuing mode
• #addCDesk: QPushButton * - button for checkout adding 
• #removeCDesk: QPushButton * - checkout removing button

• +cashWidget(QWidget *); - constructor class
• +~cashWidget() – destructor class
• +deleteCashDesk():bool –checkout deleting
• +addClienttoCDesk(int, int): bool – client arrival
• +deleteClient(int):bool – client leaving
• +getMaxClientNum():int – get the maximum number of clients
• +setProbMode(int):bool – queuing mode setting

Slots:
• addClient();
• addCashDesk();
• removeCashDesk();
• getOutOfTheQueue(int);
• openCashDesk(int);
• closeCashDesk(int);

Signals:
• resizeReq();


controlWidget class - a class for implementing a control panel
Attributes:
• +mainVLayout: QVBoxLayout * - layout for displaying items
• +getOutLayout: QHBoxLayout * - layout for displaying the client control
• +openHLayout: QHBoxLayout * - layout for displaying the checkout control
• +loseHLayout: QHBoxLayout * - layout for displaying the checkout control
• +takeBut: QPushButton * - button for adding a client
• +getOutBut: QPushButton * - client exit button
• +openDeskB: QPushButton * - button to open cash desk
• +closeDeskB: QPushButton * - button to close the checkout
• +clientLab: QLabel * - label for managing clients
• +openLab: QLabel * - label for opening cash register
• +closeLab: QLabel * - label for closing cash register
• +clientNEdit: QLineEdit * - field for entering the number of the outgoing client
• +openDEdit: QLineEdit * - field for entering the number of the opened cash register
• +closeDEdit: QLineEdit * - field for entering the number of the closed cash register

• +controlWidget(QWidget *) - class constructor
• +~controlWidget() – class destructor

Signals:
• takeTheQueue();
• getOutSig(int);
• openDeskS(int);
• closeDeskS(int);

Slots:
• getOutSlot();
• closeDeskSlot();
• openDeskSlot();


settingsWidget class - application settings implementing class
Attributes:
• +probModeLab: QLabel * - client distribution mode selecting label 
• +themeLab: QLabel * - application theme selecting label
• +probBut: QPushButton * - distribution mode selecting button
• +themeBut: QPushButton * - theme selecting button
• +probModeMenu: QMenu * - mode selection drop-down menu
• +themeMenu: QMenu * - theme exit drop-down menu
• +equalMode: QAction * - equiprobable mode selecting action
• +queueLengthMode: QAction * - action to select mode based on queue length
• +perfectWhiteTheme: QAction * - white theme selecting action
• +lemonGateTheme: QAction * - lemon theme selecting action
• +fruitBlendTheme: QAction * - orange-red theme selecting action
• +plumPlateTheme: QAction * - purple theme selecting action
• +probModeLayout: QHBoxLayout * - displaying available modes  layout
• +themeLayout: QHBoxLayout * - displaying available modes  layout
• +settLay: QVBoxLayout * - menu layout
• +settingsWidget(QWidget *) – class constructor
• +~settingsWidget() – class destructor
Signals:
• modeSig(int mode);
• perfectWhiteSig();
• lemonGateSig();
• fruitBlendSig();
• plumPlateSig();
• equalModeSig();
• queueLengthModeSig();



