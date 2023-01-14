# Enterprise-accounting-application
Enterprise accounting window application. Qt/C++, Qt version 6.2.3

1.1. Description of the subject area
Accounting consists of many cash registers. Customers come to the accounting department, choosing a cash register. After the service, the customers leave.

2. Diagrams of the object model
2.1. Use Case Diagram

![use-case](https://user-images.githubusercontent.com/103432419/212476247-cabd1d58-b899-4309-9d6e-515dc2df8088.jpg)

Picture 1. Case Diagram

2.2. Entity-relationship model

![Entity-relationship](https://user-images.githubusercontent.com/103432419/212476942-04845b16-078f-4250-bc47-2cae6b836e4b.jpg)

Picture 2. Entity-relationship diagram

2.3. Class diagram

![classDiagram](https://user-images.githubusercontent.com/103432419/212476346-4a29f80e-1814-4292-85fd-ae24b4195448.png)

Picture 3. Class diagram

2.4 List of library constructor classes used in the project to build the class diagram
QWidget - a class for implementing program user interface widgets
QHBoxLayout - layout for horizontal layout of widgets

2.5. Signal-slot connection scheme implemented in the project

![signal-slot](https://user-images.githubusercontent.com/103432419/212476386-28854667-157d-487f-80a4-64da3d6df12d.png)

Picture 4. Scheme of signal-slot connection

3. Application "Interface"
The application has an MDI interface.

3.1. Graphical representation of interface windows

3.1.1. Main window

![green](https://user-images.githubusercontent.com/103432419/212477224-4e7a0aa8-7e05-44ef-b881-5b7db46dc498.jpg)

Picture 5. Main application window with green theme selected

![orange](https://user-images.githubusercontent.com/103432419/212477339-81b7cd33-29b0-4198-9e16-f615c01c571f.png)

Picture 6. Main application window with orange theme selected

3.1.2. Software parameters window

![окноПараметров](https://user-images.githubusercontent.com/103432419/212477455-dbf380aa-bc24-4f99-9417-697320a0f8e0.png)

Picture 7. Application settings window

3.1.3. Event control window

![окноУправления](https://user-images.githubusercontent.com/103432419/212477680-2a053675-420d-4325-b05d-350bde3e9438.png)

Picture 8. Application event management window

3.1.4. Object state display window

![Рисунок9](https://user-images.githubusercontent.com/103432419/212480465-209746d3-d08a-47a1-9602-6fd97599e15c.png)

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

![Pic10](https://user-images.githubusercontent.com/103432419/212481258-7c926404-637c-4576-9892-ce86699c1606.jpg)

Picture 10. State diagram of the Accounting class



Picture 11. State diagram of the Checkout class

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



