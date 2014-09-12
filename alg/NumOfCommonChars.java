public int getNumOfCommonChars(String[] inputs) {
    // Return 0 if null / empty input or only one string is provided
    if(inputs == null || inputs.length < 2) {
        return 0;
    } else {
        //create an int array to hold # times character appears 
        int[] charCounts = new int[256];
        for(String input : inputs) {
            Set<Character> uniqueCharSet = new HashSet<Character>();
            for(int i=0; i < input.length(); i++) {
                char ch = input.charAt(i);
                if (!uniqueCharSet.contains(ch)) {
                    uniqueCharSet.add(ch);
                    charCounts[(int) ch] += 1;
                }
            }
        }

        int commonCharCount = 0;
        for (int i=0; i < 256; i++) {
            if (charCounts[i] == inputs.length()) {
                commonCharCount++;
            }
        }

        return commonCharCount;
    }
}

