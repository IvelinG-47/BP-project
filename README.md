# BP-project

BP-project is a small console C++ application for managing phone subscribers ("abonati"), their call histories, and monthly billing. It provides a text menu (Bulgarian prompts) to add and search subscribers, generate call records, compute and pay bills, and persist subscriber data to disk.

Features
- Add subscribers with: contract ID, term (1 or 2 years), name, phone number, price per minute, and monthly fee.
- List all subscribers and view basic subscriber info.
- Search by phone number.
- Find subscriber with the highest price-per-minute.
- Sort subscribers by monthly fee.
- Submenu operations:
  - List two-year subscribers sorted by name.
  - Search subscribers by term and minimum monthly fee.
- Generate random call histories (count and durations) for subscribers.
- Compute subscriber bill (monthly fee + per-call charges, calls rounded up to full minutes) and optionally mark it as paid (clears call history).
- Binary persistence: reads from and writes to TextFile1.txt as a raw binary dump of the internal subscriber structures.

Data model and limits
- Abonat struct holds: contract (dogovor), srok (term), name, phone, an array of call durations (seconds), price per minute, monthly fee, and a count of calls.
- Maximums: 30 subscribers (MAX_ABONATI) and 101 calls per subscriber (MAX_RAZGOVORI).

Build & run
1. Open the solution in Visual Studio (BP-project.vcxproj) and build the project.
2. Run the generated executable from Visual Studio or from the command line. The program uses a console menu for interaction.

Usage (menu flow)
- 1: Add subscriber (prompts for contract, term, name, phone, price/min, monthly fee).
- 2: Show all subscribers.
- 3: Search subscriber by phone.
- 4: Show subscriber with highest price/minute.
- 5: Sort subscribers by monthly fee.
- 6: Submenu (two-year listing, search by term & min fee).
- 7: Generate random calls for subscribers.
- 8: Compute and pay a subscriber's bill.
- 0: Exit (saves subscribers to TextFile1.txt in binary format).

Examples
- Add a subscriber: choose 1 and follow prompts (contract starts with "BG", term 1 or 2).
- Generate calls: after adding subscribers, choose 7 to create random call histories.
- Compute bill: choose 8 and provide the subscriber phone number; you will be prompted to confirm payment.

Known issues & notes
- The program displays prompts and messages in Bulgarian.
- Persistence is implemented as a raw binary dump of the Abonat structures to TextFile1.txt. This is not portable across compilers, architectures, or struct layout changes.
- Input validation exists but contains minor bugs (for example, one phone validation check mistakenly re-checks the contract string length). Edge cases may allow invalid phone input.
- There is no concurrency control, no encryption, and no robust error handling for malformed files; intended as a simple demo/learning utility.

Contributing / TODO
- Fix input validation bugs and make prompts available in English as an option.
- Replace raw binary persistence with a portable format (JSON or CSV).
- Add unit tests for core logic (billing, rounding rules, sorting).

License
This repository does not include an explicit license file. Treat it as "no license" until a license is added.

