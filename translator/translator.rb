file = File.open("../dashboard.html")
file_data = file.readlines.map(&:chomp)
file.close
myarry = [];
for item in file_data
    myarry.push('client.println("'+item+'");')
  end
File.write("log.txt", myarry.join("\n"))

